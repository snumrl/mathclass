# Math-library


Related author : [Jehee Lee](http://mrl.snu.ac.kr/~jehee)

Related Publication : [Siggraph 1999](http://mrl.snu.ac.kr/research/ProjectMoedit/moedit.htm)
[Graphical Models 2001](http://mrl.snu.ac.kr/research/ProjectMRA/MRA.htm)
[TVCG 2002](http://mrl.snu.ac.kr/Papers/TVCG2001.pdf)
[Siggraph 2002](http://mrl.snu.ac.kr/research/ProjectAvatar/avatar.html)


Mathclass is a library which defines data structures and its operations for character animation.

It includes point, vector, orientation and transformation.

Those data sturctures are used as fundamental elements for other libraries like PmQm.





## How to compile

 We use Cmake interface to provide cross-platform compilation.

 If you already have cmake, run
```sh
cd /dir/to/mathclass/
mkdir build
cd build
cmake ..
make -j4
```


 Then, you have mathclass.a library file. The thing you have to do is including directory, and linking mathclass.a.

## How to run examples

 We provide simple examples to help you understand.

```sh
cd /dir/to/mathclass/examples/
mkdir build
cd build
cmake ..
make
```
 

