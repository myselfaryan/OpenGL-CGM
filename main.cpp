// // libraries to be included
// #include <stdio.h>
// #include <stdlib.h>
// #include <GL/glut.h>
// #include <math.h>
// #include <time.h>
// #include <GL/gl.h>


// // declaration of variables for rotation and translation
// GLfloat Ambient_color[] = {0.1, 0.1, 0.1, 1.0};
// GLfloat Diffuse_color[] = {1.0, 1.0, 1.0, 1.0};
// GLfloat Specular_color[] = {.50, .50, .50, .10};
// GLfloat Black_color[] = {0.0f, 0.0f, 0.0f, 1.0f};
// GLfloat White_color[] = {1.0f, 1.0f, 1.0f, 1.0f};
// GLfloat Blue_color[] = {0.0f, 0.0f, 0.9f, 1.0f};
// GLfloat Yellow_color[] = {0.7f, 0.2f, 0.0f, 1.0f};
// GLfloat temp_color1[] = {0, 0, 0, 0.1};
// GLfloat scale_array[8] = {0.295, 0.40, 0.50, 0.60, 0.80, 1.0, 1.05, 1.13};
// float Moon_rotate = 0.0, Earth_rotate = 0.0, Astroid_rotate = 0.0, Mars_rotate = 0.0, Mercury_rotate = 0.0, Venus_rotate = 0.0, Jupiter_rotate = 0.0, Saturn_rotate = 0.0, Uranus_rotate = 30.0, Neptune_rotate = 60.0;
// GLfloat scale_x = 0.2, scale_y = 0.2, scale_z = 0.2;
// double rotation_deg = 2 * (3.14) / 50;
// double rotation_deg1 = 2 * (3.14) / 300;


// // to specify the different lighting effects
// void Light_initialize()
// {
//     glEnable(GL_LIGHTING);
//     glEnable(GL_LIGHT7);

//     glLightfv(GL_LIGHT7, GL_AMBIENT, Ambient_color);
//     glLightfv(GL_LIGHT7, GL_DIFFUSE, Diffuse_color);
//     glLightfv(GL_LIGHT7, GL_SPECULAR, Specular_color);
// }

// void initialize_display()
// {
//     glClearColor(0.0, 0.0, 0.0, 0.0); // backgroundcolor is green//glClearColor specifies the red, green, Blue_color, and alpha values used by glClear to clear the color buffers. xcs specified by glClearColor are clamped to the range 0 1
//     glPointSize(1.0);
//     glLineWidth(2.0);
// }

// void display_background()
// {
//     glBegin(GL_QUADS);
//     glColor3f(0.0, 0.00, 0.00);
//     glVertex3f(-01.00, 01.00, 1);

//     glColor3f(.20, 0.0, 0.70);
//     glVertex3f(01.00, 1.00, 1);

//     glColor3f(0, 0.0, 0.0);
//     glVertex3f(1.00, -1.00, 1);

//     glColor3f(.70, .10, .20);
//     glVertex3f(-1.00, -1.00, 1);
//     glEnd();

//     /*
//      glBegin(GL_QUADS);
//      glColor3f(0.0, 0.00, 0.00);
//      glVertex3f(-01.00, 01.00, 1);

//      glColor3f(0.0, 0.0, 0.0);
//      glVertex3f(01.00, 1.00, 1);

//      glColor3f(0, 0.0, 0.0);
//      glVertex3f(1.00, -1.00, 1);

//      glColor3f(0.0, 0.0, 0.0);
//      glVertex3f(-1.00, -1.00, 1);
//      glEnd();

//      */

//     glBegin(GL_POINTS);
//     srand(42);
//     // No. of stars
//     for (int i = 0; i < 500; i++)
//     {
//         double x = (rand() % 100 - 50) / 50.0;
//         double y = (rand() % 100 - 50) / 50.0;
//         double z = (rand() % 100 - 50) / 50.0;
//         auto color = rand() % 100 / 200.0 + 0.5;
//         glColor3f(color, color, color);
//         // glColor3f(0.8, 0.8, 0.8);
//         glVertex3f(x, y, z);
//     }
//     glEnd();
// }

// void display_orbit()
// {
//     glColor3f(0.5, 0.5, 0.5);

//     int i = 0;
//     for (i = 0; i < 8; i++)
//     {
//         glPushMatrix();
//         if (i == 5)
//         {
//             glRotatef(45, 1.0, 0.0, 0.0);
//         }
//         else
//         {
//             glRotatef(63, 1.0, 0.0, 0.0);
//         }

//         glScalef(scale_array[i], scale_array[i], scale_array[i]);
//         glBegin(GL_POINTS);

//         double rotation_deg2 = 0.0;
//         int i = 0;

//         // No. of dots in orbit
//         for (i = 0; i < 500; i++)
//         {
//             glVertex2d(cos(rotation_deg2), sin(rotation_deg2));
//             rotation_deg2 += rotation_deg1;
//         }

//         glEnd();
//         glPopMatrix();
//     }
// }

// void callback_planets(void)
// {
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//     display_background();
//     display_orbit();
//     glLoadIdentity();
//     glPushMatrix();
//     glEnable(GL_DEPTH_TEST);
//     glEnable(GL_COLOR_MATERIAL);

//     glPushMatrix();
//     glColor3f(0.7, 0.5, 0.0); // Sets a golden-yellow color for the Sun
//     // glScalef(scale_x, scale_y, scale_z);
//     glScalef(0.2, 0.2, 0.2); // Scales the Sun to 0.2x size in all dimensions
//     glLightfv(GL_LIGHT7, GL_POSITION, temp_color1); // Positions the light source
//     glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Yellow_color); // Makes the Sun glow
//     glutSolidSphere(1, 50, 50); // Creates a solid sphere with 50 segments
//     glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Black_color);  // Resets emission
//     glPopMatrix();

//     glScalef(0.2, 0.2, 0.2);
//     glPushMatrix();
//     glRotatef(Mercury_rotate, 0.0, 1.0, -0.5);  // Rotation on y-axis with slight tilt
//     glTranslatef(1.5, 0.0, 0.0);  // Positions Mercury 1.5 units from the Sun
//     glColor3f(1.0, 0.9, 0.0);    // Sets a yellowish color for Mercury
//     glScalef(0.08, 0.08, 0.08);  // Makes Mercury very small (0.08x size)
//     glutSolidSphere(1, 50, 50); // Creates Mercury as a sphere
//     glPopMatrix();

//     glPushMatrix();
//     glRotatef(Venus_rotate, 0.0, 1.0, -0.5);  // Rotates Venus around the Sun
//     glTranslatef(2.0, 0.0, 0.0);  // Positions Venus 2.0 units from the Sun
//     glColor3f(0.9, 0.1, 0.0);   // Sets a reddish color for Venus
//     glScalef(0.1, 0.1, 0.1);  // Makes Venus slightly larger than Mercury
//     glutSolidSphere(1, 50, 50);  // Creates Venus as a sphere
//     glPopMatrix();

//     glPushMatrix();
//     glRotatef(Earth_rotate, 0.0, 1.0, -0.5);
//     glTranslatef(2.5, 0.0, 0.0);
//     glColor3f(0.0, 0.1, 0.7);
//     glScalef(0.23, 0.23, 0.23);
//     glutSolidSphere(1, 50, 50);
//     glPushMatrix();
//     glRotatef(Moon_rotate, 0.0, 0.1, 0.05);
//     glTranslatef(1.3, 0.0, 0.0);
//     glColor3f(1.0, 1.0, 1.0);
//     glScalef(0.5, 0.5, 0.5);
//     glutSolidSphere(0.5, 50, 50);
//     glPopMatrix();
//     glPopMatrix();
//     glPushMatrix();
//     glRotatef(Mars_rotate, 0.0, 1.0, -0.5);
//     glTranslatef(-3.0, 0.0, 0.0);
//     glColor3f(0.05, 0.05, 0.01);
//     glScalef(0.17, 0.17, 0.17);
//     glutSolidSphere(1, 50, 50);
//     glPopMatrix();

//     glPushMatrix();
//     glColor3f(3.30, 3.30, 3.30); // Sets a bright gray color for asteroids
//     glRotatef(63, 1.0, 0.0, 0.0); // Tilts the asteroid belt

//     int j = 0, i = 0, rotate_d = 90;
//     float length = 2;
//     // Creates 4 rings of asteroids

//     float scale_temp[4] = {3.3, 3.4, 3.35, 3.2}; // Different scales for each ring
//     for (j = 0; j < 4; j++)
//     {
//         glPushMatrix();
//         length -= 0.3;  // Decreases point size for each ring
//         glPointSize(length);   // Sets the size of asteroid points
//         glScalef(scale_temp[j], scale_temp[j], scale_temp[j]); // Scales each ring

//         // Draws the asteroids as points in a circular pattern
//         glBegin(GL_POINTS);
//         double rotation_deg2 = 0.0 - Astroid_rotate, a = (2 * (3.14)) / rotate_d;
//         for (i = 0; i < rotate_d; i++)
//         {
//             glVertex2d(cos(rotation_deg2), sin(rotation_deg2));
//             rotation_deg2 += a;
//         }
//         rotate_d += 10; // Increases points in outer rings
//         glEnd();
//         glPopMatrix();
//     }
//     glPopMatrix();

//     glPushMatrix();
//     glRotatef(Jupiter_rotate, 0.0, 1.0, -0.5);
//     glTranslatef(-4.0, 0.0, 0.0);
//     glColor3f(0.4, 0.2, 0.0);
//     glScalef(0.5, 0.5, 0.5);
//     glutSolidSphere(1, 50, 50);
//     glPushMatrix();
//     glRotatef(Moon_rotate, 1.0, -0.5, 0.0);
//     glTranslatef(0.0, 0, 1.1);
//     glColor3f(1.0, 1.0, 1.0);
//     glScalef(0.1, 0.1, 0.1);
//     glutSolidSphere(0.5, 50, 50);
//     glPopMatrix();
//     glPopMatrix();

//     glPushMatrix();
//     glRotatef(Saturn_rotate, 0.0, 1.0, -1.0);
//     glTranslatef(-5.0, 0.0, 0.0);
//     glColor3f(0.9, 0.0, 0.0);
//     glScalef(0.4, 0.4, 0.4);
//     glutSolidSphere(1, 50, 50);
//     glPushMatrix();
//     glRotatef(45, 1.0, 0.0, 0.0);
//     glPointSize(3);
//     glColor3f(5.0, 3.0, 1.0);
//     glScalef(1.2, 1.2, 1.2);
//     glBegin(GL_POINTS);
//     double rotation_deg2 = 0.0;
//     i = 0;
//     for (i = 0; i < 50; i++)
//     {
//         glVertex2d(cos(rotation_deg2), sin(rotation_deg2));
//         rotation_deg2 += rotation_deg;
//     }
//     glEnd();

//     glPointSize(2);
//     glPopMatrix();
//     glPopMatrix();

//     glPushMatrix();
//     glRotatef(Uranus_rotate, 0.0, 1.0, -0.5);
//     glTranslatef(5.2, 0.0, 0.0);
//     glColor3f(0.0, 0.5, 0.9);
//     glScalef(0.23, 0.23, 0.23);
//     glutSolidSphere(1, 50, 50);
//     glPopMatrix();

//     glPushMatrix();
//     glRotatef(Neptune_rotate, 0.0, 1.0, -0.5);
//     glTranslatef(-5.7, 0.0, 0.0);
//     glColor3f(0.0, 0.0, 0.9);
//     glScalef(0.2, 0.2, 0.2);
//     glutSolidSphere(1, 50, 50);
//     glPopMatrix();

//     glPopMatrix();
//     glFlush();
// }

// void change_axis(int xc)
// {

//     if ((Moon_rotate >= 0 && Moon_rotate < 180))
//     {
//         scale_x -= 0.0003;
//         scale_y -= 0.0003;
//         scale_z -= 0.0003;
//     }
//     else
//     {
//         scale_x += 0.0003;
//         scale_y += 0.0003;
//         scale_z += 0.0003;
//     }

//     Moon_rotate += 2;
//     if (Moon_rotate > 360)
//     {
//         Moon_rotate -= 360;
//     }

//     Earth_rotate += 0.7;
//     if (Earth_rotate > 360)
//     {
//         Earth_rotate -= 360;
//     }

//     Mercury_rotate += 2;  // Fastest planet rotation
//     if (Mercury_rotate > 360)
//     {
//         Mercury_rotate -= 360;
//     }

//     Venus_rotate += 0.9;
//     if (Venus_rotate > 360)
//     {
//         Venus_rotate -= 360;
//     }

//     Mars_rotate += 0.5;
//     if (Mars_rotate > 360)
//     {
//         Mars_rotate -= 360;
//     }

//     Jupiter_rotate += 0.2;
//     if (Jupiter_rotate > 360)
//     {
//         Jupiter_rotate -= 360;
//     }

//     Saturn_rotate -= 0.8;
//     if (Saturn_rotate > 360)
//     {
//         Saturn_rotate += 360;
//     }

//     Uranus_rotate += 0.05;
//     if (Uranus_rotate > 360)
//     {
//         Uranus_rotate -= 360;
//     }

//     Neptune_rotate += 0.02;
//     if (Neptune_rotate > 360)
//     {
//         Neptune_rotate -= 360;
//     }

//     Astroid_rotate += 0.002;
//     if (Astroid_rotate > 360)
//     {
//         Astroid_rotate -= 360;
//     }

//     glutPostRedisplay();
//     glutTimerFunc(20, change_axis, 0);
// }

// int main(int argc, char **argv)
// {
//     glutInit(&argc, argv);                       // glutInit is used to initialize the GLUT library.
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // glutInitDisplayMode() allows you to control the mode for subsequent OpenGLUT windows. Allowable displayMode is a combination of: - GLUT_RGB. Red, green, Blue_color framebuffer
//     glutInitWindowPosition(0, 0);                // initial window position
//     glutInitWindowSize(700, 700);                // initial window size
//     glutCreateWindow("Solar System");            // creates a window named "solar System"
//     Light_initialize();                          // ambient diffuse and specular
//     initialize_display();

//     glutDisplayFunc(callback_planets); // glutDisplayFunc(void (*func)(void)) is the first and most important event callback function you will see. Whenever GLUT determines that the contents of the window need to be redisplayed, the callback function registered by glutDisplayFunc() is executed.
//     glutTimerFunc(25, change_axis, 0);

//     glutMainLoop();
//     return 0;
// }


// #define GL_SILENCE_DEPRECATION
// #include <glad/glad.h>  // Must be first!
// #include <GLFW/glfw3.h>
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <math.h>
// #include <GL/glu.h>

// // Existing color declarations
// GLfloat Ambient_color[] = {0.1, 0.1, 0.1, 1.0};
// GLfloat Diffuse_color[] = {1.0, 1.0, 1.0, 1.0};
// GLfloat Specular_color[] = {.50, .50, .50, .10};
// GLfloat Black_color[] = {0.0f, 0.0f, 0.0f, 1.0f};
// GLfloat White_color[] = {1.0f, 1.0f, 1.0f, 1.0f};
// GLfloat Blue_color[] = {0.0f, 0.0f, 0.9f, 1.0f};
// GLfloat Yellow_color[] = {0.7f, 0.2f, 0.0f, 1.0f};
// GLfloat temp_color1[] = {0, 0, 0, 0.1};
// GLfloat scale_array[8] = {0.295, 0.40, 0.50, 0.60, 0.80, 1.0, 1.05, 1.13};

// // Texture IDs
// GLuint sunTexture, earthTexture, mercuryTexture, venusTexture,
//        marsTexture, jupiterTexture, saturnTexture,
//        uranusTexture, neptuneTexture, moonTexture;

// // Existing rotation variables
// float Moon_rotate = 0.0, Earth_rotate = 0.0, Astroid_rotate = 0.0,
//       Mars_rotate = 0.0, Mercury_rotate = 0.0, Venus_rotate = 0.0,
//       Jupiter_rotate = 0.0, Saturn_rotate = 0.0, Uranus_rotate = 30.0,
//       Neptune_rotate = 60.0;

// GLfloat scale_x = 0.2, scale_y = 0.2, scale_z = 0.2;
// double rotation_deg = 2 * (3.14) / 50;
// double rotation_deg1 = 2 * (3.14) / 300;

// // Global window pointer
// GLFWwindow* window = nullptr;

// // Frame time tracking
// double lastFrame = 0.0;
// const double animationSpeed = 1.0 / 60.0; // 60 FPS target

// // Texture loading function
// GLuint loadTexture(const char* filename) {
//     if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) & (IMG_INIT_PNG | IMG_INIT_JPG))) {
//         printf("SDL_image initialization failed: %s\n", IMG_GetError());
//         return 0;
//     }

//     SDL_Surface* surface = IMG_Load(filename);
//     if (!surface) {
//         printf("Error loading texture %s: %s\n", filename, IMG_GetError());
//         return 0;
//     }

//     SDL_Surface* rgbSurface = NULL;
//     if (surface->format->format != SDL_PIXELFORMAT_RGB24) {
//         rgbSurface = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGB24, 0);
//         SDL_FreeSurface(surface);
//         if (!rgbSurface) {
//             printf("Error converting surface to RGB: %s\n", SDL_GetError());
//             return 0;
//         }
//         surface = rgbSurface;
//     }

//     GLuint textureID;
//     glGenTextures(1, &textureID);
//     glBindTexture(GL_TEXTURE_2D, textureID);

//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

//     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0,
//                  GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);

//     SDL_FreeSurface(surface);
//     return textureID;
// }

// void initSDLandTextures() {
//     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//         printf("SDL initialization failed: %s\n", SDL_GetError());
//         return;
//     }

//     // Load all textures
//     sunTexture = loadTexture("sun_texture.jpg");
//     earthTexture = loadTexture("earth_texture.jpg");
//     mercuryTexture = loadTexture("mercury_texture.jpg");
//     venusTexture = loadTexture("venus_texture.jpg");
//     marsTexture = loadTexture("mars_texture.jpg");
//     jupiterTexture = loadTexture("jupiter_texture.jpg");
//     saturnTexture = loadTexture("saturn_texture.jpg");
//     uranusTexture = loadTexture("uranus_texture.jpg");
//     neptuneTexture = loadTexture("neptune_texture.jpg");
//     moonTexture = loadTexture("moon_texture.jpg");
// }

// // Modified planet drawing function with texture
// void drawTexturedSphere(GLuint texture, float radius, int slices, int stacks) {
//     GLUquadric* quadric = gluNewQuadric();
//     gluQuadricTexture(quadric, GL_TRUE);
//     glEnable(GL_TEXTURE_2D);
//     glBindTexture(GL_TEXTURE_2D, texture);
//     gluSphere(quadric, radius, slices, stacks);
//     glDisable(GL_TEXTURE_2D);
//     gluDeleteQuadric(quadric);
// }

// void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//     glViewport(0, 0, width, height);
//     float aspect = (float)width / (float)height;
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluPerspective(45.0f, aspect, 0.1f, 100.0f);
//     glMatrixMode(GL_MODELVIEW);
// }

// void processInput(GLFWwindow* window) {
//     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//         glfwSetWindowShouldClose(window, true);
// }

// // to specify the different lighting effects
// void Light_initialize() {
//     glEnable(GL_LIGHTING);
//     glEnable(GL_LIGHT7);

//     glLightfv(GL_LIGHT7, GL_AMBIENT, Ambient_color);
//     glLightfv(GL_LIGHT7, GL_DIFFUSE, Diffuse_color);
//     glLightfv(GL_LIGHT7, GL_SPECULAR, Specular_color);
// }

// void initialize_display() {
//     glClearColor(0.0, 0.0, 0.0, 0.0);
//     glPointSize(1.0);
//     glLineWidth(2.0);
    
//     // Set up projection matrix
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);
//     glMatrixMode(GL_MODELVIEW);
// }
// void display_background() {
//     glDisable(GL_LIGHTING);  // Disable lighting for background
//     glBegin(GL_QUADS);
//     glColor3f(0.0, 0.0, 0.0);
//     glVertex3f(-01.00, 01.00, 1);
//     glVertex3f(01.00, 1.00, 1);
//     glVertex3f(1.00, -1.00, 1);
//     glVertex3f(-1.00, -1.00, 1);
//     glEnd();

//     glBegin(GL_POINTS);
//     srand(42);
//     // No. of stars
//     for (int i = 0; i < 500; i++) {
//         double x = (rand() % 100 - 50) / 50.0;
//         double y = (rand() % 100 - 50) / 50.0;
//         double z = (rand() % 100 - 50) / 50.0;
//         auto color = rand() % 100 / 200.0 + 0.5;
//         glColor3f(color, color, color);
//         glVertex3f(x, y, z);
//     }
//     glEnd();
//     glEnable(GL_LIGHTING);  // Re-enable lighting for planets
// }

// void display_orbit() {
//     glDisable(GL_LIGHTING);  // Disable lighting for orbits
//     glColor3f(0.5, 0.5, 0.5);

//     for (int i = 0; i < 8; i++) {
//         glPushMatrix();
//         if (i == 5) {
//             glRotatef(45, 1.0, 0.0, 0.0);
//         }
//         else {
//             glRotatef(63, 1.0, 0.0, 0.0);
//         }

//         glScalef(scale_array[i], scale_array[i], scale_array[i]);
//         glBegin(GL_POINTS);

//         double rotation_deg2 = 0.0;
//         // No. of dots in orbit
//         for (int j = 0; j < 500; j++) {
//             glVertex2d(cos(rotation_deg2), sin(rotation_deg2));
//             rotation_deg2 += rotation_deg1;
//         }

//         glEnd();
//         glPopMatrix();
//     }
//     glEnable(GL_LIGHTING);  // Re-enable lighting for planets
// }

// void update_animation() {
//     if ((Moon_rotate >= 0 && Moon_rotate < 180)) {
//         scale_x -= 0.0003;
//         scale_y -= 0.0003;
//         scale_z -= 0.0003;
//     }
//     else {
//         scale_x += 0.0003;
//         scale_y += 0.0003;
//         scale_z += 0.0003;
//     }

//     Moon_rotate += 2;
//     if (Moon_rotate > 360) Moon_rotate -= 360;

//     Earth_rotate += 0.7;
//     if (Earth_rotate > 360) Earth_rotate -= 360;

//     Mercury_rotate += 2;
//     if (Mercury_rotate > 360) Mercury_rotate -= 360;

//     Venus_rotate += 0.9;
//     if (Venus_rotate > 360) Venus_rotate -= 360;

//     Mars_rotate += 0.5;
//     if (Mars_rotate > 360) Mars_rotate -= 360;

//     Jupiter_rotate += 0.2;
//     if (Jupiter_rotate > 360) Jupiter_rotate -= 360;

//     Saturn_rotate += 0.1;
//     if (Saturn_rotate > 360) Saturn_rotate -= 360;

//     Uranus_rotate += 0.05;
//     if (Uranus_rotate > 360) Uranus_rotate -= 360;

//     Neptune_rotate += 0.02;
//     if (Neptune_rotate > 360) Neptune_rotate -= 360;

//     Astroid_rotate += 0.002;
//     if (Astroid_rotate > 360) Astroid_rotate -= 360;
// }

// void render_scene() {
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//     glLoadIdentity();
    
//     // Move camera back to see the scene
//     gluLookAt(0.0f, 0.0f, 5.0f,  // Eye position
//               0.0f, 0.0f, 0.0f,  // Look at position
//               0.0f, 1.0f, 0.0f); // Up vector

//     display_background();
//     display_orbit();

//     glPushMatrix();
//     glEnable(GL_DEPTH_TEST);
//     glEnable(GL_COLOR_MATERIAL);

//     // Sun
//     glPushMatrix();
//     glScalef(0.2, 0.2, 0.2);
//     glLightfv(GL_LIGHT7, GL_POSITION, temp_color1);
//     glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, White_color);
//     drawTexturedSphere(sunTexture, 1, 50, 50);
//     glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Black_color);
//     glPopMatrix();

//     glScalef(0.2, 0.2, 0.2);

//     // Mercury
//     glPushMatrix();
//     glRotatef(Mercury_rotate, 0.0, 1.0, -0.5);
//     glTranslatef(1.5, 0.0, 0.0);
//     glScalef(0.08, 0.08, 0.08);
//     drawTexturedSphere(mercuryTexture, 1, 50, 50);
//     glPopMatrix();

//     // Venus
//     glPushMatrix();
//     glRotatef(Venus_rotate, 0.0, 1.0, -0.5);
//     glTranslatef(2.0, 0.0, 0.0);
//     glScalef(0.1, 0.1, 0.1);
//     drawTexturedSphere(venusTexture, 1, 50, 50);
//     glPopMatrix();

//     // Earth and Moon
//     glPushMatrix();
//     glRotatef(Earth_rotate, 0.0, 1.0, -0.5);
//     glTranslatef(2.5, 0.0, 0.0);
//     glScalef(0.23, 0.23, 0.23);
//     drawTexturedSphere(earthTexture, 1, 50, 50);

//     glPushMatrix();
//     glRotatef(Moon_rotate, 0.0, 0.1, 0.05);
//     glTranslatef(1.3, 0.0, 0.0);
//     glScalef(0.5, 0.5, 0.5);
//     drawTexturedSphere(moonTexture, 0.5, 50, 50);
//     glPopMatrix();
//     glPopMatrix();

//     // Mars
//     glPushMatrix();
//     glRotatef(Mars_rotate, 0.0, 1.0, -0.5);
//     glTranslatef(-3.0, 0.0, 0.0);
//     glScalef(0.17, 0.17, 0.17);
//     drawTexturedSphere(marsTexture, 1, 50, 50);
//     glPopMatrix();

//     // Asteroid Belt
//     glPushMatrix();
//     glDisable(GL_LIGHTING);
//     glColor3f(3.30, 3.30, 3.30);
//     glRotatef(63, 1.0, 0.0, 0.0);
//     float length = 2;
//     float scale_temp[4] = {3.3, 3.4, 3.35, 3.2};
//     for (int j = 0; j < 4; j++) {
//         glPushMatrix();
//         length -= 0.3;
//         glPointSize(length);
//         glScalef(scale_temp[j], scale_temp[j], scale_temp[j]);
//         glBegin(GL_POINTS);
//         double rotation_deg2 = 0.0 - Astroid_rotate;
//         int rotate_d = 90 + (j * 10);
//         double a = (2 * (3.14)) / rotate_d;
//         for (int i = 0; i < rotate_d; i++) {
//             glVertex2d(cos(rotation_deg2), sin(rotation_deg2));
//             rotation_deg2 += a;
//         }
//         glEnd();
//         glPopMatrix();
//     }
//     glEnable(GL_LIGHTING);
//     glPopMatrix();

//     // Jupiter
//     glPushMatrix();
//     glRotatef(Jupiter_rotate, 0.0, 1.0, -0.5);
//     glTranslatef(-4.0, 0.0, 0.0);
//     glScalef(0.5, 0.5, 0.5);
//     drawTexturedSphere(jupiterTexture, 1, 50, 50);
//     glPopMatrix();

//     // Saturn and Rings
//     glPushMatrix();
//     glRotatef(Saturn_rotate, 0.0, 1.0, -1.0);
//     glTranslatef(-5.0, 0.0, 0.0);
//     glScalef(0.4, 0.4, 0.4);
//     drawTexturedSphere(saturnTexture, 1, 50, 50);
    
//     glPushMatrix();
//     glDisable(GL_LIGHTING);
//     glRotatef(45, 1.0, 0.0, 0.0);
//     glPointSize(3);
//     glColor3f(5.0, 3.0, 1.0);
//     glScalef(1.2, 1.2, 1.2);
//     glBegin(GL_POINTS);
//     double rotation_deg2 = 0.0;
//     for (int i = 0; i < 50; i++) {
//         glVertex2d(cos(rotation_deg2), sin(rotation_deg2));
//         rotation_deg2 += rotation_deg;
//     }
//     glEnd();
//     glEnable(GL_LIGHTING);
//     glPopMatrix();
//     glPopMatrix();

//     // Uranus
//     glPushMatrix();
//     glRotatef(Uranus_rotate, 0.0, 1.0, -0.5);
//     glTranslatef(5.2, 0.0, 0.0);
//     glScalef(0.23, 0.23, 0.23);
//     drawTexturedSphere(uranusTexture, 1, 50, 50);
//     glPopMatrix();

//     // Neptune
//     glPushMatrix();
//     glRotatef(Neptune_rotate, 0.0, 1.0, -0.5);
//     glTranslatef(-5.7, 0.0, 0.0);
//     glScalef(0.2, 0.2, 0.2);
//     drawTexturedSphere(neptuneTexture, 1, 50, 50);
//     glPopMatrix();

//     glPopMatrix();
//     glFlush();
// }

// void cleanup() {
//     // Delete all textures
//     glDeleteTextures(1, &sunTexture);
//     glDeleteTextures(1, &earthTexture);
//     glDeleteTextures(1, &mercuryTexture);
//     glDeleteTextures(1, &venusTexture);
//     glDeleteTextures(1, &marsTexture);
//     glDeleteTextures(1, &jupiterTexture);
//     glDeleteTextures(1, &saturnTexture);
//     glDeleteTextures(1, &uranusTexture);
//     glDeleteTextures(1, &neptuneTexture);
//     glDeleteTextures(1, &moonTexture);

//     IMG_Quit();
//     SDL_Quit();
//     glfwTerminate();
// }

// int main(int argc, char **argv) {
//     // Initialize GLFW
//     if (!glfwInit()) {
//         fprintf(stderr, "Failed to initialize GLFW\n");
//         return -1;
//     }

//     // Configure GLFW
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);  // Changed to COMPAT_PROFILE for legacy OpenGL

//     // Create window
//     window = glfwCreateWindow(800, 800, "Solar System", NULL, NULL);
//     if (!window) {
//         fprintf(stderr, "Failed to create GLFW window\n");
//         glfwTerminate();
//         return -1;
//     }

//     glfwMakeContextCurrent(window);

//     // Initialize GLAD
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//         fprintf(stderr, "Failed to initialize GLAD\n");
//         return -1;
//     }

//     // Set callback for window resize
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

//     // Initialize everything
//     Light_initialize();
//     initialize_display();
//     initSDLandTextures();

//     // Main loop
//     while (!glfwWindowShouldClose(window)) {
//         // Handle input
//         processInput(window);

//         // Update animation
//         double currentFrame = glfwGetTime();
//         if (currentFrame - lastFrame >= animationSpeed) {
//             update_animation();
//             lastFrame = currentFrame;
//         }

//         // Render
//         render_scene();

//         // Swap buffers and poll events
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     // Cleanup
//     cleanup();
//     return 0;
// }

#define GL_SILENCE_DEPRECATION
#include <glad/glad.h>  // Must be first!
#include <GLFW/glfw3.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <GL/glu.h>

// Existing color declarations
GLfloat Ambient_color[] = {0.1, 0.1, 0.1, 1.0};
GLfloat Diffuse_color[] = {1.0, 1.0, 1.0, 1.0};
GLfloat Specular_color[] = {.50, .50, .50, .10};
GLfloat Black_color[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat White_color[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat Blue_color[] = {0.0f, 0.0f, 0.9f, 1.0f};
GLfloat Yellow_color[] = {0.7f, 0.2f, 0.0f, 1.0f};
GLfloat temp_color1[] = {0, 0, 0, 0.1};
GLfloat scale_array[8] = {0.295, 0.40, 0.50, 0.60, 0.80, 1.0, 1.05, 1.13};

// Texture IDs
GLuint sunTexture = 0, earthTexture = 0, mercuryTexture = 0, venusTexture = 0,
       marsTexture = 0, jupiterTexture = 0, saturnTexture = 0,
       uranusTexture = 0, neptuneTexture = 0, moonTexture = 0;
bool texturesLoaded = false;

// Existing rotation variables
float Moon_rotate = 0.0, Earth_rotate = 0.0, Astroid_rotate = 0.0,
      Mars_rotate = 0.0, Mercury_rotate = 0.0, Venus_rotate = 0.0,
      Jupiter_rotate = 0.0, Saturn_rotate = 0.0, Uranus_rotate = 30.0,
      Neptune_rotate = 60.0;

GLfloat scale_x = 0.2, scale_y = 0.2, scale_z = 0.2;
double rotation_deg = 2 * (3.14) / 50;
double rotation_deg1 = 2 * (3.14) / 300;

// Global window pointer
GLFWwindow* window = nullptr;

// Frame time tracking
double lastFrame = 0.0;
const double animationSpeed = 1.0 / 60.0; // 60 FPS target

// Function declarations
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void cleanup();
void render_scene();
void update_animation();
void display_background();
void display_orbit();
// Modified texture loading function with better error handling
GLuint loadTexture(const char* filename) {
    if (!filename) return 0;

    SDL_Surface* surface = IMG_Load(filename);
    if (!surface) {
        printf("Warning: Could not load texture %s: %s\n", filename, IMG_GetError());
        return 0;
    }

    SDL_Surface* rgbSurface = NULL;
    if (surface->format->format != SDL_PIXELFORMAT_RGB24) {
        rgbSurface = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGB24, 0);
        SDL_FreeSurface(surface);
        if (!rgbSurface) {
            printf("Warning: Could not convert surface to RGB: %s\n", SDL_GetError());
            return 0;
        }
        surface = rgbSurface;
    }

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);

    SDL_FreeSurface(surface);
    return textureID;
}

// Modified planet drawing function that handles missing textures
void drawTexturedSphere(GLuint texture, float radius, int slices, int stacks) {
    GLUquadric* quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE);
    
    if (texture != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
    } else {
        glDisable(GL_TEXTURE_2D);
        // Use a default color if no texture
        glColor3f(0.8f, 0.8f, 0.8f);
    }
    
    gluSphere(quadric, radius, slices, stacks);
    glDisable(GL_TEXTURE_2D);
    gluDeleteQuadric(quadric);
}

void initSDLandTextures() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return;
    }

    if (!(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) & (IMG_INIT_JPG | IMG_INIT_PNG))) {
        printf("SDL_image initialization failed: %s\n", IMG_GetError());
        return;
    }

    // Load all textures
    sunTexture = loadTexture("sun_texture.jpg");
    earthTexture = loadTexture("earth_texture.jpg");
    mercuryTexture = loadTexture("mercury_texture.jpg");
    venusTexture = loadTexture("venus_texture.jpg");
    marsTexture = loadTexture("mars_texture.jpg");
    jupiterTexture = loadTexture("jupiter_texture.jpg");
    saturnTexture = loadTexture("saturn_texture.jpg");
    uranusTexture = loadTexture("uranus_texture.jpg");
    neptuneTexture = loadTexture("neptune_texture.jpg");
    
    // Skip moon texture if not available
    moonTexture = loadTexture("moon_texture.jpg");
    
    texturesLoaded = true;
}

void Light_initialize() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);  // Changed from LIGHT7 to LIGHT0 for better compatibility

    glLightfv(GL_LIGHT0, GL_AMBIENT, Ambient_color);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, Diffuse_color);
    glLightfv(GL_LIGHT0, GL_SPECULAR, Specular_color);
}

void initialize_display() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    
    glPointSize(2.0);
    glLineWidth(2.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 800.0f/800.0f, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    if (width == 0 || height == 0) return;
    
    glViewport(0, 0, width, height);
    float aspect = (float)width / (float)height;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
void display_background() {
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    
    // Draw black background
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.5, 1.5, -1.0);
    glVertex3f(1.5, 1.5, -1.0);
    glVertex3f(1.5, -1.5, -1.0);
    glVertex3f(-1.5, -1.5, -1.0);
    glEnd();

    // Draw stars
    glPointSize(1.0);
    glBegin(GL_POINTS);
    srand(42);
    for (int i = 0; i < 1000; i++) {
        double x = (rand() % 300 - 150) / 100.0;
        double y = (rand() % 300 - 150) / 100.0;
        double z = (rand() % 100 - 150) / 100.0;
        float brightness = (rand() % 100) / 100.0f * 0.5f + 0.5f;
        glColor3f(brightness, brightness, brightness);
        glVertex3f(x, y, z);
    }
    glEnd();
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
}

void display_orbit() {
    glDisable(GL_LIGHTING);
    glColor3f(0.3f, 0.3f, 0.3f);

    for (int i = 0; i < 8; i++) {
        glPushMatrix();
        if (i == 5) {
            glRotatef(45, 1.0, 0.0, 0.0);
        } else {
            glRotatef(63, 1.0, 0.0, 0.0);
        }
        
        glScalef(scale_array[i], scale_array[i], scale_array[i]);
        glBegin(GL_POINTS);
        for (int j = 0; j < 360; j++) {
            double angle = j * M_PI / 180.0;
            glVertex3f(cos(angle), sin(angle), 0.0);
        }
        glEnd();
        glPopMatrix();
    }
    
    glEnable(GL_LIGHTING);
}

void update_animation() {
    Moon_rotate = fmod(Moon_rotate + 2.0, 360.0);
    Earth_rotate = fmod(Earth_rotate + 0.7, 360.0);
    Mercury_rotate = fmod(Mercury_rotate + 2.0, 360.0);
    Venus_rotate = fmod(Venus_rotate + 0.9, 360.0);
    Mars_rotate = fmod(Mars_rotate + 0.5, 360.0);
    Jupiter_rotate = fmod(Jupiter_rotate + 0.2, 360.0);
    Saturn_rotate = fmod(Saturn_rotate + 0.1, 360.0);
    Uranus_rotate = fmod(Uranus_rotate + 0.05, 360.0);
    Neptune_rotate = fmod(Neptune_rotate + 0.02, 360.0);
    Astroid_rotate = fmod(Astroid_rotate + 0.002, 360.0);
}

void render_scene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Set camera position
    gluLookAt(0.0f, 2.0f, 8.0f,   // Eye position
              0.0f, 0.0f, 0.0f,   // Look at position
              0.0f, 1.0f, 0.0f);  // Up vector

    display_background();
    display_orbit();

    // Sun
    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    glMaterialfv(GL_FRONT, GL_EMISSION, White_color);
    drawTexturedSphere(sunTexture, 1.0, 50, 50);
    glMaterialfv(GL_FRONT, GL_EMISSION, Black_color);
    glPopMatrix();

    // Mercury
    glPushMatrix();
    glRotatef(Mercury_rotate, 0.0, 1.0, 0.0);
    glTranslatef(1.5, 0.0, 0.0);
    glScalef(0.08, 0.08, 0.08);
    drawTexturedSphere(mercuryTexture, 1.0, 30, 30);
    glPopMatrix();

    // Venus
    glPushMatrix();
    glRotatef(Venus_rotate, 0.0, 1.0, 0.0);
    glTranslatef(2.0, 0.0, 0.0);
    glScalef(0.1, 0.1, 0.1);
    drawTexturedSphere(venusTexture, 1.0, 30, 30);
    glPopMatrix();

    // Earth & Moon
    glPushMatrix();
    glRotatef(Earth_rotate, 0.0, 1.0, 0.0);
    glTranslatef(2.5, 0.0, 0.0);

    // Earth
    glPushMatrix();
    glScalef(0.23, 0.23, 0.23);
    drawTexturedSphere(earthTexture, 1.0, 30, 30);
    glPopMatrix();

    // Moon
    if (moonTexture) {
        glPushMatrix();
        glRotatef(Moon_rotate, 0.0, 1.0, 0.0);
        glTranslatef(0.5, 0.0, 0.0);
        glScalef(0.1, 0.1, 0.1);
        drawTexturedSphere(moonTexture, 1.0, 20, 20);
        glPopMatrix();
    }
    glPopMatrix();

    // Mars
    glPushMatrix();
    glRotatef(Mars_rotate, 0.0, 1.0, 0.0);
    glTranslatef(3.0, 0.0, 0.0);
    glScalef(0.17, 0.17, 0.17);
    drawTexturedSphere(marsTexture, 1.0, 30, 30);
    glPopMatrix();

    // Jupiter
    glPushMatrix();
    glRotatef(Jupiter_rotate, 0.0, 1.0, 0.0);
    glTranslatef(4.0, 0.0, 0.0);
    glScalef(0.5, 0.5, 0.5);
    drawTexturedSphere(jupiterTexture, 1.0, 40, 40);
    glPopMatrix();

    // Saturn
    glPushMatrix();
    glRotatef(Saturn_rotate, 0.0, 1.0, 0.0);
    glTranslatef(5.0, 0.0, 0.0);
    
    // Saturn planet
    glPushMatrix();
    glScalef(0.4, 0.4, 0.4);
    drawTexturedSphere(saturnTexture, 1.0, 40, 40);
    glPopMatrix();

    // Saturn rings
    glPushMatrix();
    glRotatef(45, 1.0, 0.0, 0.0);
    glScalef(1.0, 1.0, 0.1);
    glDisable(GL_LIGHTING);
    glColor3f(0.8f, 0.7f, 0.6f);
    drawTexturedSphere(0, 0.8, 50, 2);
    glEnable(GL_LIGHTING);
    glPopMatrix();
    
    glPopMatrix();

    // Uranus
    glPushMatrix();
    glRotatef(Uranus_rotate, 0.0, 1.0, 0.0);
    glTranslatef(6.0, 0.0, 0.0);
    glScalef(0.23, 0.23, 0.23);
    drawTexturedSphere(uranusTexture, 1.0, 30, 30);
    glPopMatrix();

    // Neptune
    glPushMatrix();
    glRotatef(Neptune_rotate, 0.0, 1.0, 0.0);
    glTranslatef(7.0, 0.0, 0.0);
    glScalef(0.2, 0.2, 0.2);
    drawTexturedSphere(neptuneTexture, 1.0, 30, 30);
    glPopMatrix();
}
void cleanup() {
    // Delete all textures if they were created
    if (sunTexture) glDeleteTextures(1, &sunTexture);
    if (earthTexture) glDeleteTextures(1, &earthTexture);
    if (mercuryTexture) glDeleteTextures(1, &mercuryTexture);
    if (venusTexture) glDeleteTextures(1, &venusTexture);
    if (marsTexture) glDeleteTextures(1, &marsTexture);
    if (jupiterTexture) glDeleteTextures(1, &jupiterTexture);
    if (saturnTexture) glDeleteTextures(1, &saturnTexture);
    if (uranusTexture) glDeleteTextures(1, &uranusTexture);
    if (neptuneTexture) glDeleteTextures(1, &neptuneTexture);
    if (moonTexture) glDeleteTextures(1, &moonTexture);

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();

    // Terminate GLFW
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

int main(int argc, char **argv) {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);  // Enable multisampling

    window = glfwCreateWindow(800, 800, "Solar System", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);  // Enable VSync

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "Failed to initialize GLAD\n");
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    initialize_display();
    Light_initialize();
    initSDLandTextures();

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        double currentTime = glfwGetTime();
        if (currentTime - lastFrame >= animationSpeed) {
            update_animation();
            lastFrame = currentTime;
        }

        render_scene();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    cleanup();
    return 0;
}