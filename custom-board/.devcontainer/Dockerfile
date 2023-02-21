# [Choice] Debian / Ubuntu version (use Debian 11, Ubuntu 18.04/22.04 on local arm64/Apple Silicon): debian-11, debian-10, ubuntu-22.04, ubuntu-20.04, ubuntu-18.04
ARG VARIANT=ubuntu-22.04
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

ARG ZEPHYR_VERSION=3.2.0
ARG ZEPHYR_SDK_VERSION=0.15.2
ARG ARM_TOOLCHAIN_VERSION=12.2.Rel1

# Fetch all required zephyr dependencies
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends git cmake ninja-build gperf \
        ccache dfu-util device-tree-compiler wget \
        python3-dev python3-pip python3-setuptools python3-tk python3-wheel xz-utils file \
        make gcc gcc-multilib g++-multilib libsdl2-dev libmagic1 sudo udev libncursesw5 openocd

# Install python3.8 (GDB dependency)
RUN apt-get -y install software-properties-common \
    && add-apt-repository ppa:deadsnakes/ppa \
    && apt-get update \
    && apt-get -y install python3.8

# Install ARM Toolchain
RUN curl -Lo gcc-arm-none-eabi.tar.xz "https://developer.arm.com/-/media/Files/downloads/gnu/${ARM_TOOLCHAIN_VERSION}/binrel/arm-gnu-toolchain-${ARM_TOOLCHAIN_VERSION}-x86_64-arm-none-eabi.tar.xz" \
    && sudo mkdir /opt/gcc-arm-none-eabi \
    && sudo tar xf gcc-arm-none-eabi.tar.xz --strip-components=1 -C /opt/gcc-arm-none-eabi \
    && rm -rf gcc-arm-none-eabi.tar.xz

# Set environment variables
ENV PATH="/home/vscode/.local/bin:/opt/gcc-arm-none-eabi/bin:${PATH}"
ENV ZEPHYR_BASE="/home/vscode/zephyrproject/zephyr"

# Grant user access to plugdev
USER vscode
RUN sudo usermod -aG plugdev $(whoami)

# Get Zephyr and install Python dependencies
RUN pip3 install --user -U west \
    && west init -m https://github.com/zephyrproject-rtos/zephyr --mr v"${ZEPHYR_VERSION}" ~/zephyrproject \
    && cd ~/zephyrproject \
    && west update  && west zephyr-export \
    && pip3 install --user -r ~/zephyrproject/zephyr/scripts/requirements.txt

# # Install Zephyr SDK
RUN cd ~ \
    && wget https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v"${ZEPHYR_SDK_VERSION}"/zephyr-sdk-"${ZEPHYR_SDK_VERSION}"_linux-x86_64.tar.gz \
    && wget -O - https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v"${ZEPHYR_SDK_VERSION}"/sha256.sum | shasum --check --ignore-missing \
    && tar xvf zephyr-sdk-"${ZEPHYR_SDK_VERSION}"_linux-x86_64.tar.gz \
    && cd zephyr-sdk-"${ZEPHYR_SDK_VERSION}" && ./setup.sh -t all -h -c 


