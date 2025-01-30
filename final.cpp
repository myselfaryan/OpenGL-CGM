#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <OpenGL/gl.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
GLuint sunTexture, earthTexture, mercuryTexture, venusTexture,
       marsTexture, jupiterTexture, saturnTexture,
       uranusTexture, neptuneTexture, moonTexture;

// Existing rotation variables
float Moon_rotate = 0.0, Earth_rotate = 0.0, Astroid_rotate = 0.0,
      Mars_rotate = 0.0, Mercury_rotate = 0.0, Venus_rotate = 0.0,
      Jupiter_rotate = 0.0, Saturn_rotate = 0.0, Uranus_rotate = 30.0,
      Neptune_rotate = 60.0;

GLfloat scale_x = 0.2, scale_y = 0.2, scale_z = 0.2;
double rotation_deg = 2 * (3.14) / 50;
double rotation_deg1 = 2 * (3.14) / 300;

// Texture loading function
GLuint loadTexture(const char* filename) {
    if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) & (IMG_INIT_PNG | IMG_INIT_JPG))) {
        printf("SDL_image initialization failed: %s\n", IMG_GetError());
        return 0;
    }

    SDL_Surface* surface = IMG_Load(filename);
    if (!surface) {
        printf("Error loading texture %s: %s\n", filename, IMG_GetError());
        return 0;
    }

    SDL_Surface* rgbSurface = NULL;
    if (surface->format->format != SDL_PIXELFORMAT_RGB24) {
        rgbSurface = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGB24, 0);
        SDL_FreeSurface(surface);
        if (!rgbSurface) {
            printf("Error converting surface to RGB: %s\n", SDL_GetError());
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

void initSDLandTextures() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
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
    moonTexture = loadTexture("moon_texture.jpg");
}

// Modified planet drawing function with texture
void drawTexturedSphere(GLuint texture, float radius, int slices, int stacks) {
    GLUquadric* quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    gluSphere(quadric, radius, slices, stacks);
    glDisable(GL_TEXTURE_2D);
    gluDeleteQuadric(quadric);
}

// to specify the different lighting effects
void Light_initialize()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT7);

    glLightfv(GL_LIGHT7, GL_AMBIENT, Ambient_color);
    glLightfv(GL_LIGHT7, GL_DIFFUSE, Diffuse_color);
    glLightfv(GL_LIGHT7, GL_SPECULAR, Specular_color);
}

void initialize_display()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(1.0);
    glLineWidth(2.0);
}

void display_background() {
  glBegin(GL_QUADS);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(-01.00, 01.00, 1);
  glVertex3f(01.00, 1.00, 1);
  glVertex3f(1.00, -1.00, 1);
  glVertex3f(-1.00, -1.00, 1);
  glEnd();

      glBegin(GL_POINTS);
      srand(42);
      // No. of stars
      for (int i = 0; i < 500; i++)
      {
          double x = (rand() % 100 - 50) / 50.0;
          double y = (rand() % 100 - 50) / 50.0;
          double z = (rand() % 100 - 50) / 50.0;
          auto color = rand() % 100 / 200.0 + 0.5;
          glColor3f(color, color, color);
          // glColor3f(0.8, 0.8, 0.8);
          glVertex3f(x, y, z);
      }
      glEnd();
}


void display_orbit()
{
    glColor3f(0.5, 0.5, 0.5);

    int i = 0;
    for (i = 0; i < 8; i++)
    {
        glPushMatrix();
        if (i == 5)
        {
            glRotatef(45, 1.0, 0.0, 0.0);
        }
        else
        {
            glRotatef(63, 1.0, 0.0, 0.0);
        }

        glScalef(scale_array[i], scale_array[i], scale_array[i]);
        glBegin(GL_POINTS);

        double rotation_deg2 = 0.0;
        int i = 0;

        // No. of dots in orbit
        for (i = 0; i < 500; i++)
        {
            glVertex2d(cos(rotation_deg2), sin(rotation_deg2));
            rotation_deg2 += rotation_deg1;
        }

        glEnd();
        glPopMatrix();
    }
}


// Modified display callback
void callback_planets(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    display_background();
    display_orbit();
    glLoadIdentity();
    glPushMatrix();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    // Sun
    glPushMatrix();
    glScalef(0.2, 0.2, 0.2);
    glLightfv(GL_LIGHT7, GL_POSITION, temp_color1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, White_color);
    drawTexturedSphere(sunTexture, 1, 50, 50);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Black_color);
    glPopMatrix();

    glScalef(0.2, 0.2, 0.2);

    // Mercury
    glPushMatrix();
    glRotatef(Mercury_rotate, 0.0, 1.0, -0.5);
    glTranslatef(1.5, 0.0, 0.0);
    glScalef(0.08, 0.08, 0.08);
    drawTexturedSphere(mercuryTexture, 1, 50, 50);
    glPopMatrix();

    // Venus
    glPushMatrix();
    glRotatef(Venus_rotate, 0.0, 1.0, -0.5);
    glTranslatef(2.0, 0.0, 0.0);
    glScalef(0.1, 0.1, 0.1);
    drawTexturedSphere(venusTexture, 1, 50, 50);
    glPopMatrix();

    // Earth and Moon
    glPushMatrix();
    glRotatef(Earth_rotate, 0.0, 1.0, -0.5);
    glTranslatef(2.5, 0.0, 0.0);
    glScalef(0.23, 0.23, 0.23);
    drawTexturedSphere(earthTexture, 1, 50, 50);

    glPushMatrix();
    glRotatef(Moon_rotate, 0.0, 0.1, 0.05);
    glTranslatef(1.3, 0.0, 0.0);
    glScalef(0.5, 0.5, 0.5);
    drawTexturedSphere(moonTexture, 0.5, 50, 50);
    glPopMatrix();
    glPopMatrix();

    // Mars
    glPushMatrix();
    glRotatef(Mars_rotate, 0.0, 1.0, -0.5);
    glTranslatef(-3.0, 0.0, 0.0);
    glScalef(0.17, 0.17, 0.17);
    drawTexturedSphere(marsTexture, 1, 50, 50);
    glPopMatrix();

    // Asteroid belt remains unchanged
    // ... [existing asteroid belt code] ...
    glPushMatrix();
    glColor3f(3.30, 3.30, 3.30);
    glRotatef(63, 1.0, 0.0, 0.0);
    int j = 0, i = 0, rotate_d = 90;
    float length = 2;
    float scale_temp[4] = {3.3, 3.4, 3.35, 3.2};
    for (j = 0; j < 4; j++)
    {
        glPushMatrix();
        length -= 0.3;
        glPointSize(length);
        glScalef(scale_temp[j], scale_temp[j], scale_temp[j]);
        glBegin(GL_POINTS);
        double rotation_deg2 = 0.0 - Astroid_rotate, a = (2 * (3.14)) / rotate_d;
        for (i = 0; i < rotate_d; i++)
        {
            glVertex2d(cos(rotation_deg2), sin(rotation_deg2));
            rotation_deg2 += a;
        }
        rotate_d += 10;
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();


    // Jupiter
    glPushMatrix();
    glRotatef(Jupiter_rotate, 0.0, 1.0, -0.5);
    glTranslatef(-4.0, 0.0, 0.0);
    glScalef(0.5, 0.5, 0.5);
    drawTexturedSphere(jupiterTexture, 1, 50, 50);
    glPopMatrix();

    // Saturn
    glPushMatrix();
    glRotatef(Saturn_rotate, 0.0, 1.0, -1.0);
    glTranslatef(-5.0, 0.0, 0.0);
    glScalef(0.4, 0.4, 0.4);
    drawTexturedSphere(saturnTexture, 1, 50, 50);
    // Saturn's rings remain unchanged
    glPushMatrix();
    glRotatef(45, 1.0, 0.0, 0.0);
    glPointSize(3);
    glColor3f(5.0, 3.0, 1.0);
    glScalef(1.2, 1.2, 1.2);
    glBegin(GL_POINTS);
    double rotation_deg2 = 0.0;
    i = 0;
    for (i = 0; i < 50; i++)
    {
        glVertex2d(cos(rotation_deg2), sin(rotation_deg2));
        rotation_deg2 += rotation_deg;
    }
    glEnd();

    glPointSize(2);
    glPopMatrix();
    // ... [existing Saturn rings code] ...
    glPopMatrix();

    // Uranus
    glPushMatrix();
    glRotatef(Uranus_rotate, 0.0, 1.0, -0.5);
    glTranslatef(5.2, 0.0, 0.0);
    glScalef(0.23, 0.23, 0.23);
    drawTexturedSphere(uranusTexture, 1, 50, 50);
    glPopMatrix();

    // Neptune
    glPushMatrix();
    glRotatef(Neptune_rotate, 0.0, 1.0, -0.5);
    glTranslatef(-5.7, 0.0, 0.0);
    glScalef(0.2, 0.2, 0.2);
    drawTexturedSphere(neptuneTexture, 1, 50, 50);
    glPopMatrix();

    glPopMatrix();
    glFlush();
}

void cleanup() {
    // Delete all textures
    glDeleteTextures(1, &sunTexture);
    glDeleteTextures(1, &earthTexture);
    glDeleteTextures(1, &mercuryTexture);
    glDeleteTextures(1, &venusTexture);
    glDeleteTextures(1, &marsTexture);
    glDeleteTextures(1, &jupiterTexture);
    glDeleteTextures(1, &saturnTexture);
    glDeleteTextures(1, &uranusTexture);
    glDeleteTextures(1, &neptuneTexture);
    glDeleteTextures(1, &moonTexture);

    IMG_Quit();
    SDL_Quit();
}

void change_axis(int xc)
{

    if ((Moon_rotate >= 0 && Moon_rotate < 180))
    {
        scale_x -= 0.0003;
        scale_y -= 0.0003;
        scale_z -= 0.0003;
    }
    else
    {
        scale_x += 0.0003;
        scale_y += 0.0003;
        scale_z += 0.0003;
    }

    Moon_rotate += 2;
    if (Moon_rotate > 360)
    {
        Moon_rotate -= 360;
    }

    Earth_rotate += 0.7;
    if (Earth_rotate > 360)
    {
        Earth_rotate -= 360;
    }

    Mercury_rotate += 2;
    if (Mercury_rotate > 360)
    {
        Mercury_rotate -= 360;
    }

    Venus_rotate += 0.9;
    if (Venus_rotate > 360)
    {
        Venus_rotate -= 360;
    }

    Mars_rotate += 0.5;
    if (Mars_rotate > 360)
    {
        Mars_rotate -= 360;
    }

    Jupiter_rotate += 0.2;
    if (Jupiter_rotate > 360)
    {
        Jupiter_rotate -= 360;
    }

    Saturn_rotate += 0.1;
    if (Saturn_rotate > 360)
    {
        Saturn_rotate -= 360;
    }

    Uranus_rotate += 0.05;
    if (Uranus_rotate > 360)
    {
        Uranus_rotate -= 360;
    }

    Neptune_rotate += 0.02;
    if (Neptune_rotate > 360)
    {
        Neptune_rotate -= 360;
    }

    Astroid_rotate += 0.002;
    if (Astroid_rotate > 360)
    {
        Astroid_rotate -= 360;
    }

    glutPostRedisplay();
    glutTimerFunc(20, change_axis, 0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Solar System");

    Light_initialize();
    initialize_display();
    initSDLandTextures();
    atexit(cleanup);

    glutDisplayFunc(callback_planets);
    glutTimerFunc(25, change_axis, 0);

    glutMainLoop();
    return 0;
}
