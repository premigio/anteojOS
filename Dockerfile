FROM debian:jessie

RUN apt-get update && apt-get install -y \
      gcc \
      make \
      nasm \
      git \
      qemu 

CMD cd sources && cd Toolchain && make all && cd .. && make clean && make all