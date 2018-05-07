FROM ubuntu:trusty
MAINTAINER Pantelis Sopasakis <p.sopasakis@gmail.com>

ENV CC=gcc

RUN apt-get update && apt-get -y install \
	libblas-dev \
	liblapack-dev \
	build-essential

WORKDIR /superscs

COPY src/ /superscs/src/
COPY include/ /superscs/include/
COPY linsys/ /superscs/linsys/
COPY tests/c/ /superscs/tests/c 
COPY scs.mk /superscs/
COPY Makefile /superscs/
COPY LICENSE.txt /superscs/
COPY examples/c/superscs_test.c /superscs/

RUN make && make PF=1 profile-run \
	&& mkdir -p /usr/lib/superscs/ \
	&& cp out/libscsdir.a /usr/lib/superscs/ \
	&& cp out/libscsindir.a /usr/lib/superscs/ \
	&& cp out/libscsdir.so /usr/lib/superscs/ \
        && cp out/libscsindir.so /usr/lib/superscs/ \
	&& ln -s /usr/lib/superscs/libscsdir.a /usr/lib/libscsdir.a \
	&& ln -s /usr/lib/superscs/libscsindir.a /usr/lib/libscsindir.a \
	&& ln -s /usr/lib/superscs/libscsdir.so /usr/lib/libscsdir.so \
        && ln -s /usr/lib/superscs/libscsindir.so /usr/lib/libscsindir.so \
	&& cp -r ./include/ /usr/include/superscs \
	&& mkdir -p /usr/include/linsys \
	&& cp linsys/amatrix.h /usr/include/linsys/ \
	&& cp linsys/common.h /usr/include/linsys/

RUN gcc superscs_test.c -o superscs_test -lscsindir -lblas -llapack -lm
