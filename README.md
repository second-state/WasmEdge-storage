# WasmEdge for Rust Storage Extension

The [WasmEdge](https://github.com/WasmEdge/WasmEdge) (formerly `SSVM`) is a high performance WebAssembly runtime optimized for server side applications. This project provides support for storage access with [Rust native storage library](https://github.com/second-state/rust_native_storage_library).

# Getting Started

## Prepare the environment

### Use our docker image (Recommanded)

Our docker image is based on `ubuntu 20.04`.

```bash
$ docker pull wasmedge/wasmedge
```

### Or setup the environment manually

Please notice that WasmEdge-storage requires cmake>=3.11

```bash
# Tools and libraries
$ sudo apt install -y \
	software-properties-common \
	cmake \
	libboost-all-dev

# WasmEdge supports both clang++ and g++ compilers
# You can choose one of them for building this project
$ sudo apt install -y gcc g++
$ sudo apt install -y clang
```

## Get WasmEdge-storage Source Code

```bash
$ git clone --recursive git@github.com:second-state/WasmEdge-storage.git
$ cd WasmEdge-storage
$ git checkout 0.8.1
```

## Prepare Machine with RocksDB

Follow [Steps](https://github.com/second-state/rust_native_storage_library#building-a-machine-to-run-this-library) to prepare a machine with RocksDB.

## Install Rust and Cargo

```bash
$ curl https://sh.rustup.rs -sSf | sh
$ source $HOME/.cargo/env
```

## Build WasmEdge-storage

WasmEdge-storage depends on WasmEdge-Core, you have to prepare WasmEdge-Core before you build WasmEdge-storage.
We provides two options for setting up the WasmEdge-Core:

### Create and Enter the Build Folder

```bash
# After pulling our WasmEdge docker image
$ docker run -it --rm \
    -v <path/to/your/WasmEdge-storage/source/folder>:/root/WasmEdge-storage \
    wasmedge/wasmedge:latest
(docker)$ cd /root/WasmEdge-storage
(docker)$ mkdir -p build && cd build
```

### Option 1. Use built-in CMakeLists to get WasmEdge-Core (Recommended)

```bash
(docker)$ cmake -DCMAKE_BUILD_TYPE=Release .. && make
```

### Option 2. Use specific version of WasmEdge-Core by giving WASMEDGE_CORE_PATH

```bash
(docker)$ cmake -DWASMEDGE_CORE_PATH=<path/to/WasmEdge/source> -DCMAKE_BUILD_TYPE=Release .. && make
```

The shared library `build/lib/libwasmedge-storage_c.so` is the C API to create the `wasmedge-storage` import object.
The header `build/include/wasmedge-storage.h` is the header of the `libwasmedge-storage_c.so` shared library.
The static library `build/lib/libwasmedgeHostModuleWasmEdgeStorage.a` is for executables linking in CMake.
