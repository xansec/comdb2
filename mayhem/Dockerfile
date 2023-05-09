FROM ubuntu AS builder

RUN apt-get update -y && DEBIAN_FRONTEND=noninteractive apt-get install -y bison                \
    clang                \
    build-essential      \
    git                  \
    gawk                 \
    cmake                \
    flex                 \
    libevent-dev         \
    liblz4-dev           \
    libprotobuf-c-dev    \
    libreadline-dev      \
    libsqlite3-dev       \
    libssl-dev           \
    libunwind-dev        \
    ncurses-dev          \
    protobuf-c-compiler  \
    tcl                  \
    uuid-dev             \
    zlib1g-dev
RUN mkdir -p /comdb2/build
WORKDIR /comdb2
COPY . .
WORKDIR /comdb2/build
RUN cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -DCMAKE_INSTALL_PREFIX=/comdb2/bb .. && make -j$(nproc) && make install

FROM ubuntu

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    libz1 \
    liblz4-tool \
    libprotobuf-c1 \
    libreadline-dev \
    libsqlite3-0 \
    libuuid1 \
    libssl-dev \
    libevent-dev         \
    liblz4-dev           \
    libssl-dev           \
    libz1 \
    libunwind8 \
    tzdata \
    && rm -rf /var/lib/apt/lists/*

COPY ./mayhem/sql.dict /

COPY --from=builder /comdb2/bb /comdb2/bb
RUN mkdir /testsuite
COPY --from=builder /comdb2/tests/sqlite_bugs.test/t00.sql /testsuite

ENV DB_NAME=fuzzdb
RUN /comdb2/bb/bin/comdb2 --create fuzzdb && \
    echo "setattr directio 0" >> /comdb2/bb/var/cdb2/fuzzdb/fuzzdb.lrl

COPY ./mayhem/entrypoint.sh /
RUN chmod a+x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]
