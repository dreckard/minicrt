# MiniCRT
An alternative Windows C runtime library for minimizing the size of output binaries. The code is from [Malcolm Smith (2014)](https://minicrt.codeplex.com/). This is (so far) just a Github upload with added Visual Studio 2010 project files.

## History
If you go searching for a smaller version of the Windows C run time library you'll eventually find a progression of updates that flow from Matt Pietrek's LIBCTINY way back in the mid 90's.

### [LIBCTINY](http://www.wheaty.net/)
* [Matt Pietrek - Remove Fatty Deposits from Your Applications Using Our 32-bit Liposuction Tools (1996)](https://www.microsoft.com/msj/archive/S569.aspx)
* [Mike V - Tiny C Runtime Library (2007)](http://www.codeproject.com/Articles/15156/Tiny-C-Runtime-Library)
* [Lee Packham - Visual C++ Runtime Hell (2009)](https://www.leepa.io/2009/06/23/visual-c-runtime-hell/)
  * Also on [github](https://github.com/leepa/libctiny)

###Also called MiniCRT
* [Google's fork (2009)](https://github.com/google/omaha/tree/5b1e98d4c6a1ff1f16249ee85fe49bff043f498a/third_party/minicrt)
* [Ben Shoof - Minicrt (2010)](http://www.benshoof.org/blog/minicrt/)

## Building
Visual Studio project files are included in vsproj/. Makefile versions for Visual Studio's nmake and MinGW make are also included.

## License
See [license file](LICENSE).
