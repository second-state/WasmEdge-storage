### 0.1.2 (2020-11-26)

Refactor:

* Remove the sample tool.
* Update to `ssvm 0.7.1`.


### 0.1.1 (2020-06-24)

Refactor:

* Update host function signature.
  * Use memory instance pointer rather than reference due to API change of host function base class.

Fixed Issues:

* UUID generation.
  * Use boost library to generate UUID.


### 0.1.0 (2020-05-20)

Features:

* SSVM Native Storage Host Functions
  * Moved from [SSVM](https://github.com/second-state/SSVM) project.
  * Supply operations to [Rust Native Storage Library](https://github.com/second-state/rust_native_storage_library) in wasm function level.

Tools:

* SSVM-Storage
  * This is a sample usage of registering `ssvm-storage` host functions into `ssvm`.
