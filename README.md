## Computer-Graphics-CS-4388

### Project 1: Description
Using 3D parallel projection (glOrtho) create a window of 640x480. Generate a triangle, rectangular, and hexagon, and a place them in the window in a way that they do not overlap.

### Project 2: Description 
Rotating colored cube using GLVertex functions and user can see various shapes by keyboard input

### Project 3: Description 
The goal of is to expand the scene you produced in assignment S2. The main additional requirements are to add perspective projection, draw a sphere, and exercise GL lighting and shading. In specific:

1. Use perspective projection with the camera placed at the center of the scene and capable of “seeing” the entire set of objects you have generated in assignment S2.
  a. Add a sphere to the library of objects created in assignment S1 / S2.
  b. Add at least 4 light sources
    i. Use different types of light sources including:
      1. point at a finite location,
      2. point at infinite,
      3. spot with different cut-offs and attenuation parameters
      4. ambient light source
    ii. Use different colors in the ambient, diffuse, and specular space for each light source
    iii. At least one light source should be visible

2. Associate material properties with each object in the scene:
  a. Use different reflection coefficients in the ambient, diffuse, and specular space for each object.
  b. Define shininess
  c. Define normals and use flat as well as smooth, shading.
  d. Use the Gourad method to find the normals of common vertices on the cube.
  e. Take at least 4 snapshots of the scene with the light sources moving from one location to another between snapshots.
  f. Draw all the snapshots in one window using different view ports.

3. Add shadowing (shadows that are due to the lighting) effects to the following objects from your scene:
  a. The cube,
  b. The sphere
