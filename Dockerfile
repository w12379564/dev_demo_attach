FROM ubuntu:xenial AS base
RUN apt-get update && \
    apt-get install -y --no-install-recommends software-properties-common gdb && \
    apt-get install -y --no-install-recommends cmake gcc g++ make && \
    rm -rf /var/lib/apt/lists/*

FROM base AS build-env
RUN apt-get update && \
    apt-get install -y libcurl4-openssl-dev && \
    rm -rf /var/lib/apt/lists/* 
WORKDIR /app
COPY . ./
RUN cmake -DCMAKE_BUILD_TYPE=Debug . 
RUN make

FROM base
WORKDIR /app
COPY --from=build-env /app ./
CMD ["./postsvr"]
