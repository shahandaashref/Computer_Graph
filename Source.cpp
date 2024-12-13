//#include <gl/freeglut.h>  
//
///* global variables */
//char title[] = "3d shapes";
//
///* initialize opengl graphics */
//void initgl() {
//    glclearcolor(0.0f, 0.0f, 0.0f, 1.0f); // set background color to black and opaque
//    glcleardepth(1.0f);                   // set background depth to farthest
//    glenable(gl_depth_test);   // enable depth testing for z-culling
//    gldepthfunc(gl_lequal);    // set the type of depth-test
//    glshademodel(gl_smooth);   // enable smooth shading
//    glhint(gl_perspective_correction_hint, gl_nicest);  // nice perspective corrections
//}
//
///* handler for window-repaint event. called back when the window first appears and
//   whenever the window needs to be re-painted. */
//void display() {
//    glclear(gl_color_buffer_bit | gl_depth_buffer_bit); // clear color and depth buffers
//    glmatrixmode(gl_modelview);     // to operate on model-view matrix
//
//    // render a color-cube consisting of 6 quads with different colors
//    glloadidentity();                 // reset the model-view matrix
//    gltranslatef(1.5f, 0.0f, -7.0f);  // move right and into the screen
//
//    glbegin(gl_quads);                // begin drawing the color cube with 6 quads
//    // top face (y = 1.0f)
//    // define vertices in counter-clockwise (ccw) order with normal pointing out
//    glcolor3f(0.0f, 1.0f, 0.0f);     // green
//    glvertex3f(1.0f, 1.0f, -1.0f);
//    glvertex3f(-1.0f, 1.0f, -1.0f);
//    glvertex3f(-1.0f, 1.0f, 1.0f);
//    glvertex3f(1.0f, 1.0f, 1.0f);
//
//    // bottom face (y = -1.0f)
//    glcolor3f(1.0f, 0.5f, 0.0f);     // orange
//    glvertex3f(1.0f, -1.0f, 1.0f);
//    glvertex3f(-1.0f, -1.0f, 1.0f);
//    glvertex3f(-1.0f, -1.0f, -1.0f);
//    glvertex3f(1.0f, -1.0f, -1.0f);
//
//    // front face  (z = 1.0f)
//    glcolor3f(1.0f, 0.0f, 0.0f);     // red
//    glvertex3f(1.0f, 1.0f, 1.0f);
//    glvertex3f(-1.0f, 1.0f, 1.0f);
//    glvertex3f(-1.0f, -1.0f, 1.0f);
//    glvertex3f(1.0f, -1.0f, 1.0f);
//
//    // back face (z = -1.0f)
//    glcolor3f(1.0f, 1.0f, 0.0f);     // yellow
//    glvertex3f(1.0f, -1.0f, -1.0f);
//    glvertex3f(-1.0f, -1.0f, -1.0f);
//    glvertex3f(-1.0f, 1.0f, -1.0f);
//    glvertex3f(1.0f, 1.0f, -1.0f);
//
//    // left face (x = -1.0f)
//    glcolor3f(0.0f, 0.0f, 1.0f);     // blue
//    glvertex3f(-1.0f, 1.0f, 1.0f);
//    glvertex3f(-1.0f, 1.0f, -1.0f);
//    glvertex3f(-1.0f, -1.0f, -1.0f);
//    glvertex3f(-1.0f, -1.0f, 1.0f);
//
//    // right face (x = 1.0f)
//    glcolor3f(1.0f, 0.0f, 1.0f);     // magenta
//    glvertex3f(1.0f, 1.0f, -1.0f);
//    glvertex3f(1.0f, 1.0f, 1.0f);
//    glvertex3f(1.0f, -1.0f, 1.0f);
//    glvertex3f(1.0f, -1.0f, -1.0f);
//    glend();  // end of drawing color-cube
//
//    // render a pyramid consists of 4 triangles
//    glloadidentity();                  // reset the model-view matrix
//    gltranslatef(-1.5f, 0.0f, -6.0f);  // move left and into the screen
//
//    glbegin(gl_triangles);           // begin drawing the pyramid with 4 triangles
//    // front
//    glcolor3f(1.0f, 0.0f, 0.0f);     // red
//    glvertex3f(0.0f, 1.0f, 0.0f);
//    glcolor3f(0.0f, 1.0f, 0.0f);     // green
//    glvertex3f(-1.0f, -1.0f, 1.0f);
//    glcolor3f(0.0f, 0.0f, 1.0f);     // blue
//    glvertex3f(1.0f, -1.0f, 1.0f);
//
//    // right
//    glcolor3f(1.0f, 0.0f, 0.0f);     // red
//    glvertex3f(0.0f, 1.0f, 0.0f);
//    glcolor3f(0.0f, 0.0f, 1.0f);     // blue
//    glvertex3f(1.0f, -1.0f, 1.0f);
//    glcolor3f(0.0f, 1.0f, 0.0f);     // green
//    glvertex3f(1.0f, -1.0f, -1.0f);
//
//    // back
//    glcolor3f(1.0f, 0.0f, 0.0f);     // red
//    glvertex3f(0.0f, 1.0f, 0.0f);
//    glcolor3f(0.0f, 1.0f, 0.0f);     // green
//    glvertex3f(1.0f, -1.0f, -1.0f);
//    glcolor3f(0.0f, 0.0f, 1.0f);     // blue
//    glvertex3f(-1.0f, -1.0f, -1.0f);
//
//    // left
//    glcolor3f(1.0f, 0.0f, 0.0f);       // red
//    glvertex3f(0.0f, 1.0f, 0.0f);
//    glcolor3f(0.0f, 0.0f, 1.0f);       // blue
//    glvertex3f(-1.0f, -1.0f, -1.0f);
//    glcolor3f(0.0f, 1.0f, 0.0f);       // green
//    glvertex3f(-1.0f, -1.0f, 1.0f);
//    glend();   // done drawing the pyramid
//
//    glutswapbuffers();  // swap the front and back frame buffers (double buffering)
//}
//
///* handler for window re-size event. called back when the window first appears and
//   whenever the window is re-sized with its new width and height */
//void reshape(glsizei width, glsizei height) {  // glsizei for non-negative integer
//    // compute aspect ratio of the new window
//    if (height == 0) height = 1;                // to prevent divide by 0
//    glfloat aspect = (glfloat)width / (glfloat)height;
//
//    // set the viewport to cover the new window
//    glviewport(0, 0, width, height);
//
//    // set the aspect ratio of the clipping volume to match the viewport
//    glmatrixmode(gl_projection);  // to operate on the projection matrix
//    glloadidentity();             // reset
//    // enable perspective projection with fovy, aspect, znear and zfar
//    gluperspective(45.0f, aspect, 0.1f, 100.0f);
//}
//
///* main function: glut runs as a console application starting at main() */
//int main(int argc, char** argv) {
//    glutinit(&argc, argv);            // initialize glut
//    glutinitdisplaymode(glut_double); // enable double buffered mode
//    glutinitwindowsize(640, 480);   // set the window's initial width & height
//    glutinitwindowposition(50, 50); // position the window's initial top-left corner
//    glutcreatewindow(title);          // create window with the given title
//    glutdisplayfunc(display);       // register callback handler for window re-paint event
//    glutreshapefunc(reshape);       // register callback handler for window re-size event
//    initgl();                       // our own opengl initialization
//    glutmainloop();                 // enter the infinite event-processing loop
//    return 0;
//}