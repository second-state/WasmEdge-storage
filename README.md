# Second State WebAssembly VM for Rust Storage Extension

The [Second State VM (SSVM)](https://github.com/second-state/ssvm) is a high performance WebAssembly runtime optimized for server side applications. This project provides support for storage access with [Rust native storage library](https://github.com/second-state/rust_native_storage_library).

# Getting Started

## Prepare the environment

### Use our docker image (Recommanded)

Our docker image is based on `ubuntu 20.04`.

```bash
$ docker pull secondstate/ssvm
```

### Or setup the environment manually

Please notice that SSVM-Storage requires cmake>=3.11

```bash
# Tools and libraries
$ sudo apt install -y \
	software-properties-common \
	cmake \
	libboost-all-dev

# And you will need to install llvm for ssvm-aot tools
$ sudo apt install -y \
	llvm-dev \
	liblld-10-dev

# SSVM supports both clang++ and g++ compilers
# You can choose one of them for building this project
$ sudo apt install -y gcc g++
$ sudo apt install -y clang
```

## Get SSVM-Storage Source Code

```bash
$ git clone --recursive git@github.com:second-state/ssvm-storage.git
$ cd ssvm-storage
$ git checkout master
```

## Prepare Machine with RocksDB

Follow [Steps](https://github.com/second-state/rust_native_storage_library#building-a-machine-to-run-this-library) to prepare a machine with RocksDB.

## Install Rust and Cargo

```bash
$ curl https://sh.rustup.rs -sSf | sh
```

## Build SSVM-Storage

SSVM-Storage depends on SSVM-Core, you have to prepare SSVM-Core before you build SSVM-Storage.
We provides two options for setting up the SSVM-Core:

### Create and Enter the Build Folder

```bash
$ cd <path/to/ssvm-storage>
$ mkdir -p build && cd build
```

### Option 1. Use built-in CMakeLists to get SSVM-Core (Recommended)

```bash
$ cmake  -DCMAKE_BUILD_TYPE=Release .. && make
```

### Option 2. Use specific version of SSVM-Core by giving SSVM_CORE_PATH

Prepare environment from [SSVM](https://github.com/second-state/SSVM) page.

```bash
$ cmake -DSSVM_CORE_PATH=<path/to/ssvm/source> -DCMAKE_BUILD_TYPE=Release .. && make
```
