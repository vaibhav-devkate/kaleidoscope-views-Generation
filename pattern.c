

#include<stdio.h>
#include<GL/glut.h>



int width=700,height=600;
int p[7],q[7],m,n,p1,q1;
float r=0,g=0.8,b=0.2;

void draw(int x,int y)
{    glLineWidth(5.0);
      glColor3f(r,g,b);
    glBegin(GL_LINE_STRIP);
     glVertex2i(p1,q1);
     glVertex2i(x,y);
    glEnd();
    glFlush();
    p1=x;q1=y;

}
void Redraw(int x,int y,int i)
{
    glPointSize(5.0);
    glColor3f(r,g,b);
    glBegin(GL_LINE_STRIP);
     glVertex2i(p[i],q[i]);
     glVertex2i(x,y);
    glEnd();
    glFlush();
    p[i]=x;q[i]=y;

}

void display()
{

}

void myinit()
{  
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
   
    gluOrtho2D(-width/2,width/2,-height/2,height/2);
    glFlush();

}
int i;


void my_click(int b,int s,int x,int y)
{
    if(b==GLUT_LEFT_BUTTON && s==GLUT_UP)
        i=0;

     else if(b==GLUT_RIGHT_BUTTON && s==GLUT_DOWN){
     
     glClear(GL_COLOR_BUFFER_BIT);
     }
}
void selectcolor(int x,int y)
{   int s=abs(x)/50;
    int t=abs(y)/50;

    if(s==0 && t==0)
        r=1.0,g=0.0,b=1.0;
    else if(s==1 && t==1)
        r=0.0,g=0.0,b=1.0;
    else if(s==2 && t==2)
        r=0.5,g=0.5,b=1.0;
    else if(s==3 && t==3)
        r=0.0,g=0.8,b=0.8;
    else if(s==4 && t==4)
        r=0.2,g=0.8,b=0.0;
    else if(s==5 && t==5)
        r=0.8,g=0.8,b=0.2;
    else
        r=1.0,g=0.4,b=0.0;

}

void my_mouse(int x,int y)
{
   m=x-width/2;
   n=height/2-y;

    if(i==0)
       {
           p1=m;q1=n;
           p[0]=-m;q[0]=-n;
           p[1]=m;q[1]=-n;
           p[2]=-m;q[2]=n;
           p[3]=-n;q[3]=m;
           p[4]=n;q[4]=-m;
           p[5]=n;q[5]=m;
           p[6]=-n;q[6]=-m;
       }
   

    selectcolor(m,n);

    draw(m,n);
    Redraw(-m,-n,0);
    Redraw(m,-n,1);
    Redraw(-m,n,2);
    Redraw(-n,m,3);
    Redraw(n,-m,4);
    Redraw(n,m,5);
    Redraw(-n,-m,6);
    i++;

}



int main(int argc,char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(5,5);
    glutInitWindowSize(width,height);
    glutCreateWindow("");

    glutDisplayFunc(display);
    glutMotionFunc(my_mouse);
   glutMouseFunc(my_click);
    myinit();
    
    glutMainLoop();

    return 0;
}

   
