#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<Windows.h>
#include<MMSystem.h>

int choice = 1, enter, fontType, flag = 0, width = 480, height = 640, startFlag = 0, activeNeutronFlag = 0,activeDeutriumFlag =0;
float activeNeutron = -.99;
float activeProton = .88;
float xA = 0, yA = 0, xB = 0, yB = 0, xC = -1.85, yC= .25, xD = 0, yD = 0,xae = 0,a = 0,b = 0,c = 0,d = 0,e = 0,f = 0;
void *font;
void *currentFont;

GLfloat qaAmbientLight[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat qaDiffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat emitLight[] = { 0.9, 0.9, 0.9, 0.01 };
GLfloat Noemit[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat qaLightPosition[] = { 0.9, 0, -3.5, 0.5 };

void introPage();
void display(	);
void init();

void setFont(void *font) {
	currentFont = font;//to set current font 
}

// x,y,z: position of string=; string
void writeText(float x, float y, float z, char *text) {
	char *i;
	glRasterPos3f(x, y, z);

	for (i = text; *i != '\0'; i++)
	{
		glColor3f(1.0, 1.0, 1.0);
		glutBitmapCharacter(currentFont, *i);
	}
}

void reShape(int w, int h) {

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float temp1 = (float)(2 * h / w);
	float temp2 = (float)(2 * w / h);
	if (w <= h)
		glFrustum(-2, 2, -temp1, temp1, 2, 20);
	else
		glFrustum(-2, 2, -temp2, temp2, 2, 20);
	glMatrixMode(GL_MODELVIEW);
}

void drawProton(double x, double y, double z) {
	
	GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat qaColor[] = { 0.9, 0.5, 0.1, 1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);

	glColor3f(0.9, 0.5, 0.1);
	glPushMatrix();
	glTranslated(x, y, z);
	glutSolidSphere(.05, 20, 20);
	glPopMatrix();
}

void drawProton1(double x, double y, double z) {

	GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat qaColor[] = { 0.9, 0.5, 0.1, 1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);

	glColor3f(0.9, 0.5, 0.1);
	glPushMatrix();
	glTranslated(x, y, z);
	glutSolidSphere(.05, 20, 20);
	glPopMatrix();
}



void drawNeutron(double x, double y, double z) {

	GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat qaColor[] = { 0.9, 0.0, 0.1, 1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);

	glColor3f(.9, 0, .1);
	glPushMatrix();
	glTranslated(x, y, z);
	glutSolidSphere(.05, 20, 20);
	glPopMatrix();
}

void drawNeutron1(double x, double y, double z) {

	GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat qaColor[] = { 0.9, 0.0, 0.1, 1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);

	glColor3f(.9, 0, .1);
	glPushMatrix();
	glTranslated(x, y, z);
	glutSolidSphere(.05, 20, 20);
	glPopMatrix();
}


void drawAtom() {
	drawProton(-0.40, 0.63, 1.0);
	drawNeutron(-.32, 0.69, 1.0);
	drawProton(-0.21, 0.72, 1.0);
	drawNeutron(-.395, 0.56, 1.0);
	drawNeutron(-.30, 0.62, 1.0);
	drawNeutron(-.20, 0.64, 1.0);
	drawProton(0.22, 0.78, 1.5);
	drawNeutron(-.25, 0.55, 1.0);
	drawProton(-0.75, 0.33, 0.5);
}

/*Deutium Atom*/
void drawAtom1() {
	drawProton1(-0.40, 0.63, 1.0);
	drawNeutron1(-.32, 0.69, 1.0);
}

void drawAtom2(float a,float b,float c,float d,float e,float f) {
	drawProton1(a, b, c);
	drawNeutron1(d, e, f);
}

void drawOtherProton(double x, double y, double z, double r, double g, double b) {

	GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat qaColor[] = { r, g, b, 1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);

	glColor3f(r, g, b);
	glPushMatrix();
	glTranslated(x, y, z);
	glutSolidSphere(.05, 20, 20);
	glPopMatrix();
}

void drawOtherProton1(double x, double y, double z, double r, double g, double b) {

	GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat qaColor[] = {0.9, 0.5, 0.1, 1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);

	glColor3f(0.9, 0.5, 0.1);
	glPushMatrix();
	glTranslated(x, y, z);
	glutSolidSphere(.05, 20, 20);
	glPopMatrix();
}

void drawOtherNeutron1(double x, double y, double z, double r, double g, double b) {

	GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat qaColor[] = {0.9, 0.0, 0.1, 1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);

	glColor3f(0.9, 0.0, 0.1);
	glPushMatrix();
	glTranslated(x, y, z);
	glutSolidSphere(.05, 20, 20);
	glPopMatrix();
}

void drawOtherNeutron(double x, double y, double z, double r, double g, double b) {

	GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat qaColor[] = { r, g, b, 1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);

	glColor3f(r, g, b);
	glPushMatrix();
	glTranslated(x, y, z);
	glutSolidSphere(.05, 20, 20);
	glPopMatrix();
}
//0.9, 0.5, 0.1
void drawOtherAtom(double r1, double g1, double b1, double r2, double g2, double b2) {
	drawOtherProton(-0.40, 0.63, 1.0, r1,g1,b1);
	drawOtherNeutron(-.32, 0.69, 1.0, r2, g2, b2);
	drawOtherProton(-0.21, 0.72, 1.0, r1, g1, b1);
	drawOtherNeutron(-.395, 0.56, 1.0, r2, g2, b2);
	drawOtherNeutron(-.30, 0.62, 1.0, r2, g2, b2);
	drawOtherNeutron(-.20, 0.64, 1.0, r2, g2, b2);
	drawOtherProton(0.22, 0.78, 1.5, r1, g1, b1);
	drawOtherNeutron(-.25, 0.55, 1.0, r2, g2, b2);
	drawOtherProton(-0.75, 0.33, 0.5, r1, g1, b1);
}

void drawOtherAtom1(double r1, double g1, double b1, double r2, double g2, double b2) {
	drawOtherNeutron1(-0.40, 0.63, 1.0, r1, g1, b1);
	drawOtherProton1(-.30, 0.62, 1.0, r2, g2, b2);
	drawOtherProton1(-.32, 0.69, 1.0, r2, g2, b2);
}

void drawOtherAtom2(double r1, double g1, double b1, double r2, double g2, double b2) {
	drawOtherNeutron1(-0.40, 0.63, 1.0, r1, g1, b1);
}




void drawSquare(int x0, int y0, int x1, int y1) {

	glColor3f(1, 0, 0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(x0, y0,0);
		glVertex3f(x0, y1,0);
		glVertex3f(x1, y1,0);
		glVertex3f(x1, y0,0);
	glEnd();
}

void writeColorText(float x, float y, float z, float r, float g, float b, char text[]) {

	GLfloat qaColor[] = { r, g, b, 1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 50);

	writeText(x,y,z, text);
}

void nuclearReactionsDescp() {

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
	glMatrixMode(GL_PROJECTION);
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0, 1.0, 1.0);

	glLoadIdentity();

	double winHt = 1.0; //half-height of window
	glOrtho(-winHt * 64 / 48.0, winHt * 64 / 48.0, -winHt, winHt, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.3, 1.3, 2.0, 0.0, 0.25, 0.0, 0.0, 1.0, 0.0);

	
	//glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);

	setFont(GLUT_BITMAP_HELVETICA_18);
	writeColorText(-0.7, 1.00, 0.0, 1, 1, 1, " ");
	writeColorText(-0.7, 1.00, 0.0, 0.8,1,0.0,"Nuclear Reactions: Fission & Fusion");
	writeColorText(-1.9, 0.5, 0.0, 1.0, 0.4, 1.0, "Nuclear Fission");

	//nuclear fission is either a nuclear reaction or a radioactive decay process in which the nucleus of an atom splits into smaller parts (lighter nuclei). 
	//The fission process often produces free neutrons and gamma photons, and releases a very large amount of energy even by the energetic standards of radioactive decay

	writeColorText(-1.8, 0.4, 0.0, 1.0, 1.0, 1.0, "Nuclear Fission is a radioactive decay process in which the nucleus of an atom splits into smaller parts ");
	writeColorText(-1.8, 0.35, 0.0, 1.0, 1.0, 1.0, "The fission process often produces free neutrons and gamma photons and releases a very large amount of energy");
	writeColorText(-1.8, 0.20, 0.0, 0.9, 1.0, 0.2, "Fission Equation");

	writeColorText(-1.7, 0.12, 0.0, 1.0, 1.0, 1.0, "1");
	writeColorText(-1.67, 0.10, 0.0, 1.0, 1.0, 1.0, "n");
	writeColorText(-1.7, 0.05, 0.0, 1.0, 1.0, 1.0, "0");

	writeColorText(-1.60, 0.12, 0.0, 1.0, 1.0, 1.0, "+");
	
	writeColorText(-1.53, 0.16, 0.0, 1.0, 1.0, 1.0, "235");
	writeColorText(-1.44, 0.14, 0.0, 1.0, 1.0, 1.0, "U");
	writeColorText(-1.53, 0.09, 0.0, 1.0, 1.0, 1.0, "92");

	writeColorText(-1.35, 0.16, 0.0, 1.0, 1.0, 1.0, "--->");

	writeColorText(-1.18, 0.20, 0.0, 1.0, 1.0, 1.0, "[");
	writeColorText(-1.15, 0.24, 0.0, 1.0, 1.0, 1.0, "235");
	writeColorText(-1.06, 0.22, 0.0, 1.0, 1.0, 1.0, "U");
	writeColorText(-1.15, 0.15, 0.0, 1.0, 1.0, 1.0, "92");
	writeColorText(-1.00, 0.24, 0.0, 1.0, 1.0, 1.0, "]");

	writeColorText(-0.96, 0.26, 0.0, 1.0, 1.0, 1.0, "--->");

	writeColorText(-0.76, 0.34, 0.0, 1.0, 1.0, 1.0, "141");
	writeColorText(-0.67, 0.32, 0.0, 1.0, 1.0, 1.0, "Ba");
	writeColorText(-0.76, 0.25, 0.0, 1.0, 1.0, 1.0, "56");

	writeColorText(-0.58, 0.35, 0.0, 1.0, 1.0, 1.0, "+");
	
	writeColorText(-0.51, 0.41, 0.0, 1.0, 1.0, 1.0, "92");
	writeColorText(-0.42, 0.39, 0.0, 1.0, 1.0, 1.0, "Kr");
	writeColorText(-0.51, 0.32, 0.0, 1.0, 1.0, 1.0, "36");

	writeColorText(-0.33, 0.41, 0.0, 1.0, 1.0, 1.0, "+");

	writeColorText(-0.27, 0.43, 0.0, 1.0, 1.0, 1.0, "3");
	writeColorText(-0.22, 0.49, 0.0, 1.0, 1.0, 1.0, "1");
	writeColorText(-0.19, 0.47, 0.0, 1.0, 1.0, 1.0, "n");
	writeColorText(-0.22, 0.42, 0.0, 1.0, 1.0, 1.0, "0");

	writeColorText(-0.10, 0.47, 0.0, 1.0, 1.0, 1.0, "+");

	writeColorText(-0.01, 0.49, 0.0, 1.0, 1.0, 1.0, "200 MeV");

	//fusion reation
	writeColorText(-1.9, -0.2, 0.0, 1.0, 0.4, 1.0, "Nuclear Fusion");
	writeColorText(-1.8, -0.3, 0.0, 1.0, 1.0, 1.0, "Nuclear Fusion is a reaction in which two or more atomic nuclei come close enough to form one or more different atomic nuclei and subatomic particles");
	writeColorText(-1.8, -0.35, 0.0, 1.0, 1.0, 1.0, "The difference in mass between the reactants and products is manifested as the release of large amounts of energy");
}

void changeColor(float r, float g, float b) {
	GLfloat qaColor[] = { r, g, b, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaColor);

}

void nuclearFission() {
	printf("Choice 3: Nuclear Fission\n");

	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
	glMatrixMode(GL_PROJECTION);
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0, 1.0, 1.0);

	if (!activeNeutronFlag) {
		writeText(-175, 30, 0, "Free Slow moving Neutron bombarding uranium atom");
		writeText(-200, 322, 0, "235");
		writeText(-180, 318, 0, "U");
		writeText(-175, 310, 0, "92");
	}

	if (activeNeutronFlag) {
		setFont(GLUT_BITMAP_HELVETICA_18);
		glColor3f(1.0, 1.0, 1.0);

		writeText(-200, 322, 0, "236");
		writeText(-180, 318, 0, "U");
		writeText(-175, 310, 0, "92");

		writeText(-200, 200, 0, "Compund Nucleus formed after absorbing free neutron");
		writeText(350, 450, 0, "92");
		writeText(370, 446, 0, "Kr");
		writeText(375, 438, 0, "36");
		
		writeText(350, 220, 0, "141");
		writeText(370, 215, 0, "Ba");
		writeText(375, 206, 0, "56");
		writeText(-180, 30, 0, "Uranium absorbs neutrons and splits into 2 nuclie: Barium and Krypton");
		writeText(-180, 15, 0, "The unstable Uranium also release 3 more free neutrons");
		writeText(-90.0, 425.0, 0.0, "During this process, 3 more neutrons are released which continue to take part in a chain reaction");

	}

	glLoadIdentity();

	double winHt = 1.0; //half-height of window
	glOrtho(-winHt * 64 / 48.0, winHt * 64 / 48.0, -winHt, winHt, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.3, 1.3, 2.0, 0.0, 0.25, 0.0, 0.0, 1.0, 0.0);


	drawAtom();
	writeText(-1.8, 0.7, 0.0, "Press 's' to start; 'q' to quit;");

	glPushMatrix();
	glScalef(.75, .75, .7);
	drawNeutron(-1.9, activeNeutron, 0.0);
	glPopMatrix();

	if (activeNeutronFlag)
	{
		int i;
		while (xA <= 2 && yA <= 0.5/* && xB <= 2 && yB <= 0.05*/) {

			printf("both met");
			//glTranslated(2.0, 0.5, 0);
			glPushMatrix();
			glTranslated(xA, yA, 0);
			drawOtherAtom(0.0, 0.7, 0.1, .3, 0, .6);
			glPopMatrix();

			xA = xA + 0.007;
			yA = yA + 0.0017;

			//glTranslated(2.0, 0.05, 0);
			/*glPushMatrix();
			glTranslated(xB, yB, 0);
			drawOtherAtom(0.0, 0.7, 0.1, 0.7, 1.0, 1.0);
			glPopMatrix();
			xB = xB + 0.07;
			yB = yB + 0.01;*/
			//ask mam here

			glFlush();
			glutSwapBuffers();
			display();
		}

		while (xC <= -1.70 && yC <= .75) {
			
				glPushMatrix();
				glScalef(.75, .75, .7);
				//drawNeutron(-1.85, 0.25, 0.0);
				drawNeutron(xC, yC, 0.0);
				drawNeutron(xC+0.2, yC+0.2, 0.0);
				drawNeutron(xC + 0.1, yC + 0.1, 0.0);
				glPopMatrix();

				printf("br atom x y: %f, %f\n", xC + 0.1, yC + 0.1);
				xC = xC + 0.003;
				yC = yC + 0.01;

				glFlush();
				glutSwapBuffers();
				display();
			}

			/*glPushMatrix();
			glTranslatef(2.5, 2, 0);
			drawNeutron(0, 0, 0);
			glPopMatrix();
			glFlush();
			glutSwapBuffers();
			display();
		}*/
		glPushMatrix();
		glTranslated(xA, yA, 0);
		drawOtherAtom(0.0, 0.7, 0.1, .3, 0, .6);
		glPopMatrix();
		glFlush();
		glutSwapBuffers();

		glPushMatrix();
		glTranslated(2, 0.05, 0);
		drawOtherAtom(0.0, 0.7, 0.1, 0.7, 1.0, 1.0);
		glPopMatrix();
		glFlush();
		glutSwapBuffers();

		glPushMatrix();
		glScalef(.75, .75, .7);
		drawNeutron(-1.503001, 0.87, 0.0);
		glPopMatrix();

		glPushMatrix();
		glScalef(.75, .75, .7);
		drawNeutron(-1.70, 0.75, 0.0);
		glPopMatrix();

		glPushMatrix();
		glScalef(.75, .75, .7);
		drawNeutron(-1.602999, 0.84, 0.0);
		glPopMatrix(); 
	}

	glFlush();
	glutSwapBuffers();

}



void keyBoardFunc(unsigned char key, int x, int y) {
	int i;
	if (key == 's') {
		printf("activeNeutronFlag = : %d", activeNeutronFlag);
		for (i = 0; i < 1000; i++) {
			activeNeutron = activeNeutron + 0.001;//change this later
			//activeProton = activeProton + 0.001;
			display();
		}
		activeNeutronFlag = 1;
		printf("activeNeutronFlag = : %d", activeNeutronFlag);
		display();
	}
	if (key == 'k') {

		//printf("activeNeutronFlag = : %d", activeNeutronFlag);
		for (i = 0; i < 500; i++) {
			xae = xae + 0.001;//change this later
			display();
		}
		activeDeutriumFlag = 1;
		printf("activeDeutriumFlag = : %d", activeDeutriumFlag);
		display();
	}

	if (key == 'r') {
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	if (key == 'q')
	{
		exit(0);
	}

	if (key == 'z')
	{
		exit(0);
	}
	

}

void nuclearFissionOperation() {

}

void nuclearFusion() {

	printf("Choice 4: Fusion\n");
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
	glMatrixMode(GL_PROJECTION);
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0, 1.0, 1.0);
	//pratyush just do the fusion part here. Dont change anything. I have drawn the nucleus. U just have to copy the following
	//4 lines and paste every time to draw a nucleus. Change the translae points by trial and error method
	if (!activeDeutriumFlag) {
		writeText(-175, 30, 0, "2 deuterium(hydrogen isotope) atom fuses...");
		writeText(-190, 322, 0, "2");
		writeText(-180, 318, 0, "H");
	}

	if (activeDeutriumFlag) {
		setFont(GLUT_BITMAP_HELVETICA_18);
		glColor3f(1.0, 1.0, 1.0);

		writeText(-190, 322, 0, "4");
		writeText(-180, 318, 0, "He");
		writeText(-165, 309, 0, "2");
		writeText(-100, 318, 0, "High Energy(unstable) He breaks into its isotope of He-3 ");

		writeText(-200, 200, 0, "2 deutrium atoms fuses to form He-4");
		writeText(360, 453, 0, "3");
		writeText(370, 446, 0, "He");
		writeText(385, 438, 0, "2");

		
		writeText(370, 215, 0, "High energy Neutron");
		//writeText(-180, 30, 0, "Uranium absorbs neutrons and splits into 2 nuclie: Barium and Krypton");
		//writeText(-180, 15, 0, "The unstable He-4 also release 3 more free neutrons");
		writeText(-90.0, 425.0, 0.0, "This is one of the most rare Deuterium fussion reaction... ");

	}

	glLoadIdentity();

	double winHt = 1.0; //half-height of window
	glOrtho(-winHt * 64 / 48.0, winHt * 64 / 48.0, -winHt, winHt, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.3, 1.3, 2.0, 0.0, 0.25, 0.0, 0.0, 1.0, 0.0);
	drawAtom1();
	writeText(-1.8, 0.7, 0.0, "Press 'k' to start and 'q' to quit");
	glPushMatrix();
	drawAtom2(-0.40, 0.2 + xae, 1.0, -0.34, 0.13 + xae, 1.0);
	glPopMatrix();

	if (activeDeutriumFlag)
	{
		int i;
		while (xA <= 2 && yA <= 0.5/* && xB <= 2 && yB <= 0.05*/) {

			printf("both met");
			glPushMatrix();
			glTranslated(xA, yA, 0);
			drawOtherAtom1(0.0, 0.7, 0.1, .3, 0, .6);
			glPopMatrix();

			xA = xA + 0.007;
			yA = yA + 0.0017;

			glFlush();
			glutSwapBuffers();
			display();
		}


		glPushMatrix();
		glTranslated(xA, yA, 0);
		drawOtherAtom1(0.9, 0.0, 0.1, .3, 0, .6);
		glPopMatrix();
		glFlush();
		glutSwapBuffers();

		glPushMatrix();
		glTranslated(2, 0.05, 0);
		drawOtherAtom2(0.9, 0.0, 0.1, 0.9, 0.0, 0.1);
		glPopMatrix();
		glFlush();
		glutSwapBuffers();

	}

	glFlush();
	glutSwapBuffers();

}


void introPage() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (choice == 1) {
		glClearColor(0.7, 1.0, 0.4, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);

		setFont(GLUT_BITMAP_TIMES_ROMAN_24);
		glColor3f(1.0, 1.0, 1.0);
		writeText(155.0, 475.0, 0.0, "PES Institute of Technology-Bangalore South Campus");

		glColor3f(1.0, 1.0, 1.0);
		writeText(145.0, 450.0, 0.0, "Departement of Computer Science & Engineering, BE/BTech");

		setFont(GLUT_BITMAP_HELVETICA_18);
		glColor3f(1.0, 1.0, 1.0);
		writeText(170, 300, 0.0, "Computer Graphics Mini Project: Nuclear Reactions");

		setFont(GLUT_BITMAP_HELVETICA_18);
		glColor3f(1.0, 1.0, 1.0);
		writeText(190, 270, 0, "Team:");

		glColor3f(1.0, 1.0, 1.0);
		writeText(190, 250, 0, "Prakruth Nagaraj: 1PE15CS104");
		glColor3f(1.0, 1.0, 1.0);
		writeText(190, 230, 0, "Pratyush Debnath: 1PE15CS108");

		glColor3f(1.0, 1.0, 1.0);
		writeText(500, 15, 0.0, "Menu Button: Right Click");
		printf("choice 1\n");
		glLoadIdentity();
	}
	else if (choice == 2) {
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		printf("choice 2\n");
		nuclearReactionsDescp();
	}
	else if (choice == 3) {
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		printf("choice 3\n");
		nuclearFission();
		glFlush();
	}
	else if (choice == 4) {
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		printf("choice 4\n");
		nuclearFusion();
	}
	glFlush();
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	introPage();
	glFlush();
}

void menu(int id)
{
	switch (id)
	{

	case 1:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		choice = 1;
		introPage();
		break;

	case 2:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		choice = 2;
		//nuclearReactionsDescp();
		break;
	case 3:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		choice = 3;
		//nuclearFission();
		break;
	case 4:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		choice = 4;
		//nuclearFusion();
		break;
	case 5:
		exit(0);
	}
	display();
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
//	glMatrixMode(GL_MODELVIEW);
}

void initLighting() {

	// Enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set lighting intensity and color
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	// Set the light position
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

}


int main() {

	//glutInit(&argc, argc);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(1366, 768);
	glutCreateWindow("Nuclear Reactions");

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	init();
	initLighting();
	enter = 1;
	//choice = 1;
	int subMenu = glutCreateMenu(menu);
	glutAddMenuEntry("Nuclear Fission", 3);
	glutAddMenuEntry("Nuclear Fusion", 4);
	glutCreateMenu(menu);
	glutAddMenuEntry("Welcome Page", 1);
	glutAddMenuEntry("Introduction: Nuclear Reactions", 2);
	glutAddSubMenu("Nuclear Rections Display", subMenu);
	glutAddMenuEntry("Exit, Thank you", 5);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	//glutMouseFunc(myMouse);
	//  	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyBoardFunc);
//	glutIdleFunc(idleFunc);

	glutMainLoop();
}
