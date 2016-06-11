FROM alpine:latest

RUN apk add -U gcc g++ clang make

ENTRYPOINT make -f /source/Makefile
