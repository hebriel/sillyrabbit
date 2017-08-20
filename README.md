
# sillyrabbit
## Important notes

Really small OpenGL engine using SFML, please note the following :

 * It's just a way to simplify the code. You STILL need to know OpenGL
 * The engine can support OpenGL 1.x to 4.x, please note that "glext.h" is included automatically by some headers.
 * The engine is based on [SFML 2.4.2](http://sfml-dev.org), you need to know this library for some aspects (such as events).

**This project is incomplete.** So I won't do a wiki for a while. I don't recommend you to use sillyrabbit for now, as there is no documentation.

## Code example

In the previous versions you could find a code example here, in this document. Now an example project is available in the ***examples*** folder.

## Linkage

By compiling with the "SILLYRABBIT_DEBUG" define, you have access to the Debug Mode of the Engine. That adds functionnalities like **force unlock** (A+R for 5 seconds) and outputs more interesting stuff to the console.

The convention ask you to compile the debug version of the engine to "libsillyrabbit-d" and the release version to "libsillyrabbit" (Same convention as SFML's). The prebuilt binaries (currently only for linux32) also uses that convention. Use libsillyrabbit-d.so in debug and libsillyrabbit.so for release.
