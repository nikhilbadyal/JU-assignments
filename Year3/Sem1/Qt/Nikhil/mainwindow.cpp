#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include <QTime>
#include <cmath>
#include <time.h>
#include<bits/stdc++.h>

#define maxHt 1800
#define maxWd 1000
#define maxVer 10000
#define fwidth 600
#define fheight 600
using namespace std;
int gridsize=1;
int flag = 0;
int polygon_flag = 0;

void MainWindow::delay(){
    QTime dietime = QTime::currentTime().addMSecs(1);
    while(QTime::currentTime()<dietime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}
QImage img=QImage(1000,1000,QImage::Format_RGB888);
QImage rgbImage=QImage(256,256,QImage::Format_RGB888);
QImage colorImage=QImage(100,100,QImage::Format_RGB888);
QImage colorImageDynamic=QImage(440,20,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->x_axis->hide();
    ui->y_axis->hide();
    connect(ui->frame,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_Pressed()));
    connect(ui->frame,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
   // connect(ui->rgb_frame,SIGNAL(Mouse_Pos()),this,SLOT(rgb_Mouse_Pressed()));
   // connect(ui->rgb_frame,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(rgb_showMousePosition(QPoint&)));
    on_rgb_clicked();
    setcolorFrame();
    srand(time(NULL));
    int random_r = rand()%256;
    int random_g = rand()%256;
    int random_b = rand()%256;
    //ui->blue_scroller->setValue(random_b);
    ui->r_scroll_bar->setValue(random_r);
    ui->g_scroll_bar->setValue(random_g);
    ui->b_scroll_bar->setValue(random_b);
    on_rgb_clicked();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_rgb_clicked()
{
    //int b=ui->blue_scroller->value();
//    for(int i=0;i<rgbImage.width();i++){
//        for(int j=0;j<rgbImage.height();j++){
//            rgbImage.setPixel(i,j,qRgb(i,j,b));
//            }
//        }
    //ui->rgb_frame->setPixmap(QPixmap::fromImage(rgbImage));
}
//void MainWindow::on_blue_scroller_valueChanged(){
//    //on_rgb_clicked();
//}
void MainWindow::rgb_showMousePosition(QPoint &pos)
{
    //int x = pos.x();
    //int y = pos.y();
    //int b = ui->blue_scroller->value();
    //ui->rgb_mouse_movement->setText(" R : "+QString::number(x)+", G : "+QString::number(y)+", B : "+QString::number(b));
    //setcolorFrameDynamic(x,y,b);
}
void MainWindow::rgb_Mouse_Pressed()
{
    //int x = (ui->rgb_frame->x);
   // int y = (ui->rgb_frame->y);
//    ui->fillcolor_rlabel->setText(QString::number(x));
//    ui->fillcolor_glabel->setText(QString::number(y));
//    ui->fillcolor_blabel->setText(QString::number(ui->blue_scroller->value()));
//    ui->r_scroll_bar->setValue(x);
//    ui->g_scroll_bar->setValue(y);
    //ui->b_scroll_bar->setValue(ui->blue_scroller->value());
}
void MainWindow::on_r_scroll_bar_valueChanged(){
    setcolorFrame();
}
void MainWindow::on_g_scroll_bar_valueChanged(){
    setcolorFrame();
}
void MainWindow::on_b_scroll_bar_valueChanged(){
    setcolorFrame();
}
void MainWindow::setcolorFrame(){
    int r=ui->r_scroll_bar->value();
    int g=ui->g_scroll_bar->value();
    int b=ui->b_scroll_bar->value();
    ui->fillcolor_rlabel->setText(QString::number(r));
    ui->fillcolor_glabel->setText(QString::number(g));
    ui->fillcolor_blabel->setText(QString::number(b));
    for(int i=0;i<colorImage.width();i++){
        for(int j=0;j<colorImage.height();j++){
            colorImage.setPixel(i,j,qRgb(r,g,b));
            }
        }
    ui->color_frame->setPixmap(QPixmap::fromImage(colorImage));
}
//void MainWindow::setcolorFrameDynamic(int r,int g,int b){
//    for(int i=0;i<colorImageDynamic.width();i++){
//        for(int j=0;j<colorImageDynamic.height();j++){
//            colorImageDynamic.setPixel(i,j,qRgb(r,g,b));
//            }
//        }
//    //ui->color_frame_dynamic->setPixmap(QPixmap::fromImage(colorImageDynamic));
//}
void MainWindow::point(int x,int y, int r=255, int g=255, int b=255)
{
    if(gridsize == 1) img.setPixel(x,y,qRgb(r,g,b));
    else {
        x = (x/gridsize)*gridsize;
        y = (y/gridsize)*gridsize;
        for(int i=x+1;i <  x + gridsize;i++) {
            for(int j=y+1;j < y + gridsize;j++) {
                img.setPixel(i,j,qRgb(r,g,b));
            }
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::showMousePosition(QPoint &pos)
{
    int x = (pos.x() - ui->frame->width()/2)/gridsize;
    int y = (ui->frame->height()/2 - pos.y())/gridsize;
    if((ui->frame->height()/2 - pos.y())%gridsize > 0){
        y=y+1;
    }
    if((pos.x() - ui->frame->width()/2)%gridsize < 0){
        x=x-1;
    }
    ui->mouse_movement->setText(" X : "+QString::number(x)+", Y : "+QString::number(y));
    //ui->rgb_mouse_pos->setText(" X : "+QString::number(x)+", Y : "+QString::number(y));
}
void MainWindow::Mouse_Pressed()
{
    int x = (ui->frame->x - ui->frame->width()/2)/gridsize;
    int y = (ui->frame->height()/2 - ui->frame->y)/gridsize;
    if((ui->frame->height()/2 - ui->frame->y)%gridsize > 0){
        y=y+1;
    }
    if((ui->frame->x - ui->frame->width()/2)%gridsize < 0){
        x=x-1;
    }
    ui->mouse_pressed->setText(" X : "+QString::number(x)+", Y : "+QString::number(y));
    if(ui->pickcolor_checkBox->isChecked()){
        int r = img.pixelColor(ui->frame->x,ui->frame->y).red();
        int g = img.pixelColor(ui->frame->x,ui->frame->y).green();
        int b = img.pixelColor(ui->frame->x,ui->frame->y).blue();
        ui->rvalue_label->setText(QString::number(r));
        ui->gvalue_label->setText(QString::number(g));
        ui->bvalue_label->setText(QString::number(b));
    }
    else{
        if(flag==0){
            on_set_point1_clicked();
            flag=1;
            point(ui->frame->x,ui->frame->y,0, 255, 0);
        }
        else{
            on_set_point2_clicked();
            flag=0;
            point(ui->frame->x,ui->frame->y,0, 0, 255);
        }
        if(polygon_flag == 1){
            on_setvertex_clicked();
        }
    }
}

void MainWindow::on_show_axes_clicked()
{

    if(ui->show_axes->isChecked())
    {
        for(int j=0;j<=ui->frame->width();j+=gridsize)
        {
            point(img.width()/2,j,235,222,52);
        }
        for(int i=0;i<=ui->frame->height();i+=gridsize)
        {
            point(i,img.height()/2,235,222,52);
        }
    }
    else{
        on_setgridbutton_clicked();
    }
}
void MainWindow::on_resetButton_clicked()
{
    for(int j=0;j<img.height();j++)
    {
        for(int i=0;i<img.width();i++)
        {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::on_setgridbutton_clicked(){
    on_resetButton_clicked();
    gridsize=ui->gridspinbox->value();
    if(gridsize>1)
    {
        for(int i=0;i<img.width();i+=gridsize)
        {
            for(int j=0;j<img.height();j++)
            {
                img.setPixel(i,j,qRgb(180,179,181));
                img.setPixel(j,i,qRgb(180,179,181));
            }
        }
        ui->frame->setPixmap(QPixmap::fromImage(img));
    }
}
void MainWindow::on_set_point1_clicked()
{
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);
    int x = (ui->frame->x - ui->frame->width()/2)/gridsize;
    int y = (ui->frame->height()/2 - ui->frame->y)/gridsize;
    if((ui->frame->height()/2 - ui->frame->y)%gridsize > 0){
        y=y+1;
    }
    if((ui->frame->x - ui->frame->width()/2)%gridsize < 0){
        x=x-1;
    }
    ui->set_point_1_text->setText("( "+QString::number(x)+", "+QString::number(y)+" )");

}
void MainWindow::on_set_point2_clicked()
{
    p2.setX(ui->frame->x);
    p2.setY(ui->frame->y);
    int x = (ui->frame->x - ui->frame->width()/2)/gridsize;
    int y = (ui->frame->height()/2 - ui->frame->y)/gridsize;
    if((ui->frame->height()/2 - ui->frame->y)%gridsize > 0){
        y=y+1;
    }
    if((ui->frame->x - ui->frame->width()/2)%gridsize < 0){
        x=x-1;
    }
    ui->set_point_2_text->setText("( "+QString::number(x)+", "+QString::number(y)+" )");
}
// DDA (Digital Differential Analyzer) line drawing algorithm
void MainWindow::on_DDALine_clicked()
{
    clock_t start, end;
    start = clock();
    int r=ui->r_scroll_bar->value();
    int g=ui->g_scroll_bar->value();
    int b=ui->b_scroll_bar->value();
    DDAline(r,g,b);
    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    ui->dda_time_taken->setText("Time Taken : "+QString::number(time_taken,'g',6)+"s");
}
void MainWindow::DDAline(int r, int g, int b) {
    double x1 = p1.x()/gridsize;
    double y1 = p1.y()/gridsize;
    double x2 = p2.x()/gridsize;
    double y2 = p2.y()/gridsize;
    double xinc, yinc, step;
    double slope = fabs(y2-y1)/fabs(x2-x1);
    if(slope  <= 1.00) {
        xinc = 1;
        yinc = slope;
        step = fabs(x2 - x1);
    } else {
        xinc = 1/slope;
        yinc = 1;
        step = fabs(y2 - y1);
    }
    if(x1 > x2) xinc *= -1;
    if(y1 > y2) yinc *= -1;
    double x = x1*gridsize + gridsize/2;
    double y = y1*gridsize + gridsize/2;
    for(int i=0;i<=step;i++) {
        point(x,y,r,g,b);
        //delay();
        x += xinc * gridsize;
        y += yinc * gridsize;
    }
}
// Bresenham line drawing algorithm
void MainWindow::on_bresenhamLine_clicked()
{
    clock_t start, end;
    start = clock();

    int x1 = p1.x()/gridsize;
    int y1 = p1.y()/gridsize;
    int x2 = p2.x()/gridsize;
    int y2 = p2.y()/gridsize;
    int dx = fabs(x2 - x1);
    int dy = fabs(y2 - y1);

    int xinc = (x1 > x2 ? -1 : 1);
    int yinc = (y1 > y2 ? -1 : 1);
    bool flag = 1;
    int x = x1*gridsize + gridsize/2;
    int y = y1*gridsize + gridsize/2;

    if(dy > dx) {
        // if slope > 1, then swap
        int temp;
        temp=dx; dx=dy; dy=temp;
        temp=x; x=y; y=temp;
        temp=xinc; xinc=yinc; yinc=temp;
        flag = 0;
    }

    int decision = 2*dy - dx;
    int step = dx;
    for(int i=0;i<=step;i++) {
        if(flag) point(x,y,247,75,7);
        else point(y,x,247,75,7);
        //delay();
        if(decision < 0) {
            x += xinc*gridsize;
            decision += 2*dy;
        } else {
            x += xinc*gridsize;
            y += yinc*gridsize;
            decision += 2*dy - 2*dx;
        }
    }
    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    ui->bresenham_time_taken->setText("Time Taken : "+QString::number(time_taken,'g',7)+"s");
}
// Mid point circle drawing algorithm
void MainWindow::on_midPointCircle_clicked()
{
    clock_t start, end;
    start = clock();

    int x = (ui->frame->x - ui->frame->width()/2)/gridsize;
    int y = (ui->frame->height()/2 - ui->frame->y)/gridsize;
    if((ui->frame->height()/2 - ui->frame->y)%gridsize > 0){
        y=y+1;
    }
    if((ui->frame->x - ui->frame->width()/2)%gridsize < 0){
        x=x-1;
    }
    ui->center_label_circle->setText(" X : "+QString::number(x)+", Y : "+QString::number(y));

    int r = ui->radiusspinbox->value();
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);

    int x0 = p1.x()/gridsize;
    int y0 = p1.y()/gridsize;
    x0 = x0*gridsize + gridsize/2;
    y0 = y0*gridsize + gridsize/2;

    x = 0;
    y = r*gridsize;

    int p = (5/4 - r)*gridsize;
    while(x <= y) {
        delay();
        point(x0 - x, y0 - y,240,30,7);
        point(x0 + x, y0 - y,240,30,7);
        point(x0 - x, y0 + y,240,30,7);
        point(x0 + x, y0 + y,240,30,7);
        point(x0 - y, y0 - x,240,30,7);
        point(x0 + y, y0 - x,240,30,7);
        point(x0 - y, y0 + x,240,30,7);
        point(x0 + y, y0 + x,240,30,7);
        x += gridsize;
        if(p <= 0) {
            p += 2*x + 3;
        } else {
            p += 2*x + 1 - 2*y + 5;
            y -= gridsize;
        }
    }

    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    ui->mid_point_circle_time_taken->setText("Time Taken : "+QString::number(time_taken,'g',6)+"s");
}
//Bresenham circle drawing algorithm
void MainWindow::on_bresenhamCircle_clicked()
{
    clock_t start, end;
    start = clock();

    int x = (ui->frame->x - ui->frame->width()/2)/gridsize;
    int y = (ui->frame->height()/2 - ui->frame->y)/gridsize;
    if((ui->frame->height()/2 - ui->frame->y)%gridsize > 0){
        y=y+1;
    }
    if((ui->frame->x - ui->frame->width()/2)%gridsize < 0){
        x=x-1;
    }
    ui->center_label_circle->setText(" X : "+QString::number(x)+", Y : "+QString::number(y));

    int r = ui->radiusspinbox->value();
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);

    int x0 = p1.x()/gridsize;
    int y0 = p1.y()/gridsize;
    x0 = x0*gridsize + gridsize/2;
    y0 = y0*gridsize + gridsize/2;

    x = 0;
    y = r*gridsize;
    int p = (3 - 2*r)*gridsize;//parameter
    while(y >= x) {
        delay();
        point(x0 - x, y0 - y,7,23,242);
        point(x0 + x, y0 - y,7,23,242);
        point(x0 - x, y0 + y,7,23,242);
        point(x0 + x, y0 + y,7,23,242);
        point(x0 - y, y0 - x,7,23,242);
        point(x0 + y, y0 - x,7,23,242);
        point(x0 - y, y0 + x,7,23,242);
        point(x0 + y, y0 + x,7,23,242);

        x += gridsize;
        if(p <= 0) {
            p += 4*x + 6;
        } else {
            p += 4*(x-y) + 10;
            y -= gridsize;
        }
    }

    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    ui->bresenham_circle_time_taken->setText("Time Taken : "+QString::number(time_taken,'g',6)+"s");
}
//Polar Circle drawing algorithm
void MainWindow::on_polarCircle_clicked(){
    clock_t start, end;
    start = clock();

    int x = (ui->frame->x - ui->frame->width()/2)/gridsize;
    int y = (ui->frame->height()/2 - ui->frame->y)/gridsize;
    if((ui->frame->height()/2 - ui->frame->y)%gridsize > 0){
        y=y+1;
    }
    if((ui->frame->x - ui->frame->width()/2)%gridsize < 0){
        x=x-1;
    }
    ui->center_label_circle->setText(" X : "+QString::number(x)+", Y : "+QString::number(y));

    int r = ui->radiusspinbox->value();
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);

    int x0 = p1.x()/gridsize;
    int y0 = p1.y()/gridsize;
    x0 = x0*gridsize + gridsize/2;
    y0 = y0*gridsize + gridsize/2;

    x = r*gridsize;
    y = 0;

    point(x0 - x, y0 - y);
    point(x0 + x, y0 - y);
    point(x0 - x, y0 + y);
    point(x0 + x, y0 + y);
    point(x0 - y, y0 - x);
    point(x0 + y, y0 - x);
    point(x0 - y, y0 + x);
    point(x0 + y, y0 + x);

    double theta=0,dtheta=(1.0/r);
    while(x>y)
    {
        theta+=dtheta;
        x=round(gridsize*r*cos(theta));
        y=round(gridsize*r*sin(theta));
        delay();
        point(x0 - x, y0 - y);
        point(x0 + x, y0 - y);
        point(x0 - x, y0 + y);
        point(x0 + x, y0 + y);
        point(x0 - y, y0 - x);
        point(x0 + y, y0 - x);
        point(x0 - y, y0 + x);
        point(x0 + y, y0 + x);
    }

    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    ui->polar_circle_time_taken->setText("Time Taken : "+QString::number(time_taken,'g',6)+"s");
}
// Ellipse drawing algorithm
void MainWindow::on_ellipse_clicked()
{
    clock_t start, end;
    start = clock();

    int x = (ui->frame->x - ui->frame->width()/2)/gridsize;
    int y = (ui->frame->height()/2 - ui->frame->y)/gridsize;
    if((ui->frame->height()/2 - ui->frame->y)%gridsize > 0){
        y=y+1;
    }
    if((ui->frame->x - ui->frame->width()/2)%gridsize < 0){
        x=x-1;
    }
    ui->center_label_ellipse->setText(" X : "+QString::number(x)+", Y : "+QString::number(y));

    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);
    int rx = ui->r1spinbox->value();
    int ry = ui->r2spinbox->value();
    int x_centre=p1.x();
    int y_centre=p1.y();
    int k = ui->gridspinbox->value();//GridSize

    x_centre=(x_centre/k)*k+k/2;
    y_centre=(y_centre/k)*k+k/2;

    x=0;
    y=ry;

    int rx2=rx*rx;
    int ry2=ry*ry;
    int tworx2=2*rx2;
    int twory2=2*ry2;
    int px=0.0;
    int py=tworx2*y;
    //For first region
    int p1=ry2-rx2*ry+(0.25)*rx2; //Initial value of decision paramemter

    while(px<py)
    {
        delay();
        point(x_centre+x*k,y_centre+y*k,8, 252, 0);
        point(x_centre-x*k,y_centre+y*k,8, 252, 0);
        point(x_centre-x*k,y_centre-y*k,8, 252, 0);
        point(x_centre+x*k,y_centre-y*k,8, 252, 0);

        x++;
        px+=twory2;
        if(p1>=0) {
            y--;
            py-=tworx2;
            p1=p1+ry2+px-py;

        }  else{
            p1=p1+ry2+px;
        }
    }

    //For second region
    p1=ry2*((double)x+0.5)*((double)x+0.5)+rx2*(y-1)*(y-1)-rx2*ry2; //Initial value of decision paramemter


    while(y>=0)
    {
        delay();
        point(x_centre+x*k,y_centre+y*k,8, 252, 0);
        point(x_centre-x*k,y_centre+y*k,8, 252, 0);
        point(x_centre-x*k,y_centre-y*k,8, 252, 0);
        point(x_centre+x*k,y_centre-y*k,8, 252, 0);

        y--;
        py-=tworx2;
        if(p1<=0){
            x++;
            px+=twory2;
            p1=p1+rx2-py+px;

        }  else  {
            p1=p1+rx2-py;
        }
    }

    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    ui->bresenham_ellipse_time_taken->setText("Time Taken : "+QString::number(time_taken,'g',6)+"s");
}
void MainWindow::floodfillutil(int x, int y, int r, int g, int b) {
    if(x < 0 || y < 0 || x >= img.width() || y >= img.height()) return;
    //if(img.pixel(x,y) == qRgb(r,g,b) || img.pixel(x,y) != qRgb(0,0,0)) return;
    if(img.pixel(x,y) != qRgb(0,0,0)) return;
    point(x,y,r,g,b);
    delay();
    floodfillutil(x - gridsize, y, r,g,b);
    floodfillutil(x + gridsize, y, r,g,b);
    floodfillutil(x, y - gridsize, r,g,b);
    floodfillutil(x, y + gridsize, r,g,b);
    /*
    floodfillutil(x - gridsize, y - gridsize, r,g,b);
    floodfillutil(x - gridsize, y + gridsize, r,g,b);
    floodfillutil(x + gridsize, y - gridsize, r,g,b);
    floodfillutil(x + gridsize, y + gridsize, r,g,b);
    */
}
void MainWindow::on_floodfill_clicked()
{
    clock_t start, end;
    start = clock();
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);
    int x = p1.x()/gridsize;
    int y = p1.y()/gridsize;
    x = x*gridsize + gridsize/2;
    y = y*gridsize + gridsize/2;
    point(x,y,0,0,0);
    int r=ui->r_scroll_bar->value();
    int g=ui->g_scroll_bar->value();
    int b=ui->b_scroll_bar->value();
    floodfillutil(x,y,r,g,b);
    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    ui->flood_fill_time_taken->setText("Time Taken : "+QString::number(time_taken,'g',6)+"s");
}
void MainWindow::boundaryfillutil(int x, int y, QRgb edgecolour, int r, int g, int b) {
    if(x < 0 || y < 0 || x >= img.width() || y >= img.height()) return;
    if(img.pixel(x,y) == edgecolour || img.pixel(x,y) == qRgb(r,g,b)) return;
    point(x,y,r,g,b);
    delay();
    boundaryfillutil(x - gridsize, y, edgecolour,r,g,b);
    boundaryfillutil(x + gridsize, y, edgecolour,r,g,b);
    boundaryfillutil(x, y - gridsize, edgecolour,r,g,b);
    boundaryfillutil(x, y + gridsize, edgecolour,r,g,b);
    /*
    boundaryfillutil(x - gridsize, y - gridsize, edgecolour,r,g,b);
    boundaryfillutil(x + gridsize, y - gridsize, edgecolour,r,g,b);
    boundaryfillutil(x - gridsize, y + gridsize, edgecolour,r,g,b);
    boundaryfillutil(x + gridsize, y + gridsize, edgecolour,r,g,b);
    */
}
void MainWindow::on_boundaryfill_clicked()
{
    clock_t start, end;
    start = clock();
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);
    int x = p1.x()/gridsize;
    int y = p1.y()/gridsize;
    x = x*gridsize + gridsize/2;
    y = y*gridsize + gridsize/2;
    point(x,y,0,0,0);
    int r=ui->r_scroll_bar->value();
    int g=ui->g_scroll_bar->value();
    int b=ui->b_scroll_bar->value();
    int edge_r=ui->rvalue_label->text().toInt();
    int edge_g=ui->gvalue_label->text().toInt();
    int edge_b=ui->bvalue_label->text().toInt();
    boundaryfillutil(x,y,qRgb(edge_r,edge_g,edge_b),r,g,b);
    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    ui->boundary_fill_time_taken->setText("Time Taken : "+QString::number(time_taken,'g',6)+"s");
}
void MainWindow::on_polygon_mode_clicked(){
    if(polygon_flag == 0){
        ui->polygon_mode->setText("Polygon (Set)");
        polygon_flag = 1;
    }
    else{
        ui->polygon_mode->setText("Polygon (Un-Set)");
        polygon_flag = 0;
    }
}
// polygon drawing
std::vector<std::pair<int,int> > vertex_list;   //vertex list
void MainWindow::on_setvertex_clicked()
{
    int x=(ui->frame->x/gridsize)*gridsize+gridsize/2;
    int y=(ui->frame->y/gridsize)*gridsize+gridsize/2;
    vertex_list.push_back(std::make_pair(x,y));
    int i=vertex_list.size();
    if(i>=2)
    {
        //storing the latest edge in table
        storeEdgeInTable(vertex_list[i-2].first, vertex_list[i-2].second, vertex_list[i-1].first, vertex_list[i-1].second);//storage of edges in edge table.
        //drawing the latest edge
        p1.setX(vertex_list[i-1].first);
        p1.setY(vertex_list[i-1].second);
        p2.setX(vertex_list[i-2].first);
        p2.setY(vertex_list[i-2].second);
        on_DDALine_clicked();
    }
}
void MainWindow::on_clearvertex_clicked()
{
    vertex_list.clear();
    initEdgeTable();
}
// Scanline Filling
typedef struct edgebucket
{
    int ymax;   //max y-coordinate of edge
    float xofymin;  //x-coordinate of lowest edge point updated only in aet
    float slopeinverse;
}EdgeBucket;
typedef struct edgetabletup
{
    // the array will give the scanline number
    // The edge table (ET) with edges entries sorted
    // in increasing y and x of the lower end

    int countEdgeBucket;    //no. of edgebuckets
    EdgeBucket buckets[maxVer];
}EdgeTableTuple;
EdgeTableTuple EdgeTable[maxHt], ActiveEdgeTuple;
void MainWindow::initEdgeTable()
{
    int i;
    for (i=0; i<maxHt; i++)
    {
        EdgeTable[i].countEdgeBucket = 0;
    }

    ActiveEdgeTuple.countEdgeBucket = 0;
}
void insertionSort(EdgeTableTuple *ett)
{
    int i,j;
    EdgeBucket temp;

    for (i = 1; i < ett->countEdgeBucket; i++)
    {
        temp.ymax = ett->buckets[i].ymax;
        temp.xofymin = ett->buckets[i].xofymin;
        temp.slopeinverse = ett->buckets[i].slopeinverse;
        j = i - 1;

    while ((temp.xofymin < ett->buckets[j].xofymin) && (j >= 0))
    {
        ett->buckets[j + 1].ymax = ett->buckets[j].ymax;
        ett->buckets[j + 1].xofymin = ett->buckets[j].xofymin;
        ett->buckets[j + 1].slopeinverse = ett->buckets[j].slopeinverse;
        j = j - 1;
    }
        ett->buckets[j + 1].ymax = temp.ymax;
        ett->buckets[j + 1].xofymin = temp.xofymin;
        ett->buckets[j + 1].slopeinverse = temp.slopeinverse;
    }
}
void storeEdgeInTuple (EdgeTableTuple *receiver,int ym,int xm,float slopInv)
{
    (receiver->buckets[(receiver)->countEdgeBucket]).ymax = ym;
    (receiver->buckets[(receiver)->countEdgeBucket]).xofymin = (float)xm;
    (receiver->buckets[(receiver)->countEdgeBucket]).slopeinverse = slopInv;
    insertionSort(receiver);
    (receiver->countEdgeBucket)++;
}
void MainWindow::storeEdgeInTable (int x1,int y1, int x2, int y2)
{
    float m,minv;
    int ymaxTS,xwithyminTS, scanline;

    if (x2==x1){
        minv=0.000000;
    }
    else{
        m = ((float)(y2-y1))/((float)(x2-x1));
        if (y2==y1)
            return;
        minv = (float)1.0/m;
    }
    if (y1>y2){
        scanline=y2;
        ymaxTS=y1;
        xwithyminTS=x2;
    }
    else{
        scanline=y1;
        ymaxTS=y2;
        xwithyminTS=x1;
    }
    storeEdgeInTuple(&EdgeTable[scanline],ymaxTS,xwithyminTS,minv);
}
void removeEdgeByYmax(EdgeTableTuple *Tup,int yy)
{
    int i,j;
    for (i=0; i< Tup->countEdgeBucket; i++)
    {
        if (Tup->buckets[i].ymax == yy)
        {
            for ( j = i ; j < Tup->countEdgeBucket -1 ; j++ )
                {
                Tup->buckets[j].ymax =Tup->buckets[j+1].ymax;
                Tup->buckets[j].xofymin =Tup->buckets[j+1].xofymin;
                Tup->buckets[j].slopeinverse = Tup->buckets[j+1].slopeinverse;
                }
                Tup->countEdgeBucket--;
            i--;
        }
    }
}
void updatexbyslopeinv(EdgeTableTuple *Tup)
{
    int i;

    for (i=0; i<Tup->countEdgeBucket; i++)
    {
        (Tup->buckets[i]).xofymin =(Tup->buckets[i]).xofymin + (Tup->buckets[i]).slopeinverse;
    }
}
void MainWindow::on_scanlinefill_clicked()
{
    clock_t start, end;
    start = clock();
    int i, j, x1, ymax1, x2, ymax2, FillFlag = 0, coordCount;
    for (i=0; i<maxHt; i++){
        for (j=0; j<EdgeTable[i].countEdgeBucket; j++){
            storeEdgeInTuple(&ActiveEdgeTuple,EdgeTable[i].buckets[j].ymax,EdgeTable[i].buckets[j].xofymin,EdgeTable[i].buckets[j].slopeinverse);
        }
        removeEdgeByYmax(&ActiveEdgeTuple, i);
        insertionSort(&ActiveEdgeTuple);
        j = 0;
        FillFlag = 0;
        coordCount = 0;
        x1 = 0;
        x2 = 0;
        ymax1 = 0;
        ymax2 = 0;
        while (j<ActiveEdgeTuple.countEdgeBucket){
            if (coordCount%2==0){
                x1 = (int)(ActiveEdgeTuple.buckets[j].xofymin);
                ymax1 = ActiveEdgeTuple.buckets[j].ymax;
                if (x1==x2){
                    if (((x1==ymax1)&&(x2!=ymax2))||((x1!=ymax1)&&(x2==ymax2))){
                        x2 = x1;
                        ymax2 = ymax1;
                    }
                    else{
                        coordCount++;
                    }
                }
                else{
                        coordCount++;
                }
            }
            else{
                x2 = (int)ActiveEdgeTuple.buckets[j].xofymin;
                ymax2 = ActiveEdgeTuple.buckets[j].ymax;

                FillFlag = 0;
                if (x1==x2){
                    if (((x1==ymax1)&&(x2!=ymax2))||((x1!=ymax1)&&(x2==ymax2))){
                        x1 = x2;
                        ymax1 = ymax2;
                    }
                    else{
                        coordCount++;
                        FillFlag = 1;
                    }
                }
                else{
                    coordCount++;
                    FillFlag = 1;
                }
                if(FillFlag){
                    p1.setX(x1);p1.setY(i);
                    p2.setX(x2);p2.setY(i);
                    on_DDALine_clicked();
                }
            }
            j++;
        }
        updatexbyslopeinv(&ActiveEdgeTuple);
    }
    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    ui->scanline_fill_time_taken->setText("Time Taken : "+QString::number(time_taken,'g',6)+"s");
    vertex_list.clear();
    initEdgeTable();
}

void MainWindow::poly_draw(std::vector<std::pair<int,int> > vlist, int r, int g, int b) {
    for(int i=0;i<vlist.size()-1;i++)
    {
        p2.setX(vlist[i].first); p2.setY(vlist[i].second);
        p1.setX(vlist[i+1].first); p1.setY(vlist[i+1].second);
        DDAline(r,g,b);
    }
}
void mat_mult(double a[3][3], int b[3], double res[3]){
    int i,j;
    for(i=0;i<3;i++){
        res[i]=0;
        for(j=0;j<3;j++)
            res[i]+=(a[i][j]*b[j]);
    }
}

void MainWindow::on_translation_clicked()
{
    clock_t start, end;
    start = clock();
    double tx = ui->xtranslate->value();
    double ty = ui->ytranslate->value();
    int k = ui->gridspinbox->value();

    std::vector<std::pair<int,int> > old_vertex = vertex_list;
    for(int i=0;i<vertex_list.size();i++)
    {
        old_vertex.push_back(vertex_list[i]);
    }

    tx*=k;
    ty*=k;
    ty=-ty;
    int i,len=vertex_list.size();

    // matrix for translation
    double mat[3][3]={{1,0,tx},{0,1,ty},{0,0,1}};

    int coord[3];
    double res[3];
    for(i=0;i<len;i++)
    {
        coord[0]=vertex_list[i].first;
        coord[1]=vertex_list[i].second;
        coord[2]=1;
        mat_mult(mat,coord,res);
        vertex_list[i].first= res[0]/res[2];
        vertex_list[i].second= res[1]/res[2];
    }
    int r = ui->r_scroll_bar->value();
    int g = ui->g_scroll_bar->value();
    int b = ui->b_scroll_bar->value();
    poly_draw(old_vertex,255,255,255);
    poly_draw(vertex_list,r,g,b);
    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    ui->translation_time_taken->setText("Time Taken : "+QString::number(time_taken,'g',6)+"s");
}

void MainWindow::on_scaling_clicked()
{
    clock_t start, end;
    start = clock();
    double sx = ui->xscale->value();
    double sy = ui->yscale->value();
    gridsize = ui->gridspinbox->value();

    std::vector<std::pair<int,int> > old_vertex;
    for(int i=0;i<vertex_list.size();i++)
    {
        old_vertex.push_back(vertex_list[i]);
    }

    //Point about which to be scaled
    int piv_x=(ui->frame->x/gridsize)*gridsize+gridsize/2;
    int piv_y=(ui->frame->y/gridsize)*gridsize+gridsize/2;

    int i,len=vertex_list.size();

    // matrix for scaling
    double mat[3][3]={{sx,0,0},{0,sy,0},{0,0,1}};
    int coord[3];
    double res[3];
    for(i=0;i<len;i++)
    {
        int* coord=(int*)malloc(3*sizeof(int));
        coord[0]=vertex_list[i].first-piv_x;
        coord[1]=piv_y-vertex_list[i].second;
        coord[2]=1;
        mat_mult(mat,coord,res);
        vertex_list[i].first=res[0]/res[2]+piv_x;
        vertex_list[i].second=piv_y-res[1]/res[2];

    }
    int r = ui->r_scroll_bar->value();
    int g = ui->g_scroll_bar->value();
    int b = ui->b_scroll_bar->value();
    poly_draw(old_vertex,255,255,255);
    poly_draw(vertex_list,r,g,b);
    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    ui->scaling_time_taken->setText("Time Taken : "+QString::number(time_taken,'g',6)+"s");
}

void MainWindow::on_rotation_clicked()
{
    clock_t start, end;
    start = clock();
    int angle = ui->anglespinbox->value();
    gridsize = ui->gridspinbox->value();

    std::vector<std::pair<int,int> > old_vertex;
    for(int i=0;i<vertex_list.size();i++)
    {
        old_vertex.push_back(vertex_list[i]);
    }

    double dang=(double)angle*M_PI/180.0;
    double sinang=sin(dang);
    double cosang=cos(dang);

    //Point about which to be rotated
    int piv_x=(ui->frame->x/gridsize)*gridsize+gridsize/2;
    int piv_y=(ui->frame->y/gridsize)*gridsize+gridsize/2;

    int i,len=vertex_list.size();

    // matrix for rotation
    double mat[3][3]={{cosang,-sinang,0},{sinang,cosang,0},{0,0,1}};
    int coord[3];
    double res[3];
    for(i=0;i<len;i++)
    {
        coord[0]=vertex_list[i].first-piv_x;
        coord[1]=piv_y-vertex_list[i].second;
        coord[2]=1;
        mat_mult(mat,coord,res);
        vertex_list[i].first=res[0]/res[2]+piv_x;
        vertex_list[i].second=piv_y-res[1]/res[2];
    }

    int r = ui->r_scroll_bar->value();
    int g = ui->g_scroll_bar->value();
    int b = ui->b_scroll_bar->value();
    poly_draw(old_vertex,255,255,255);
    poly_draw(vertex_list,r,g,b);
    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    ui->rotation_time_taken->setText("Time Taken : "+QString::number(time_taken,'g',6)+"s");
}

void MainWindow::on_shearing_clicked()
{
    clock_t start, end;
    start = clock();
    double shx = ui->xshear->value();
    double shy = ui->yshear->value();
    gridsize = ui->gridspinbox->value();

    std::vector<std::pair<int,int> > old_vertex;
    for(int i=0;i<vertex_list.size();i++)
    {
        old_vertex.push_back(vertex_list[i]);
    }

    //Point about which to be scaled
    int piv_x=(ui->frame->x/gridsize)*gridsize+gridsize/2;
    int piv_y=(ui->frame->y/gridsize)*gridsize+gridsize/2;

    int i,len=vertex_list.size();

    // matrix for shearing
    double mat[3][3]={{1,shx,0},{shy,1,0},{0,0,1}};
    int coord[3];
    double res[3];
    for(i=0;i<len;i++)
    {
        coord[0]=vertex_list[i].first-piv_x;
        coord[1]=piv_y-vertex_list[i].second;
        coord[2]=1;
        mat_mult(mat,coord,res);
        vertex_list[i].first=res[0]/res[2]+piv_x;
        vertex_list[i].second=piv_y-res[1]/res[2];
    }
    int r = ui->r_scroll_bar->value();
    int g = ui->g_scroll_bar->value();
    int b = ui->b_scroll_bar->value();
    poly_draw(old_vertex,255,255,255);
    poly_draw(vertex_list,r,g,b);
    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    ui->shearing_time_taken->setText("Time Taken : "+QString::number(time_taken,'g',6)+"s");
}

void MainWindow::on_reflection_clicked()
{
    clock_t start, end;
    start = clock();
    int i,len=vertex_list.size();

    double dx=p1.x()-p2.x();
    double dy=p1.y()-p2.y();

    double a=-dy;
    double b=dx;
    double c=p1.x()*dy-p1.y()*dx;

    for(i=0;i<len;i++)
    {
        int x1=vertex_list[i].first;
        int y1=vertex_list[i].second;

        vertex_list[i].first=(int)((double)x1-(double)(2*a*(a*x1+b*y1+c))/(double)((a*a+b*b)));
        vertex_list[i].second=(int)((double)y1-(double)(2*b*(a*x1+b*y1+c))/(double)((a*a+b*b)));
    }
    poly_draw(vertex_list,255,255,255);
    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    ui->reflection_time_taken->setText("Time Taken : "+QString::number(time_taken,'g',6)+"s");
}
// ----------------------------------------------CLIPPING-----------------------------------------------
int clipper_points[4][2];
void MainWindow::on_setcorner1_clicked()
{
    cp1.setX((ui->frame->x/gridsize)*gridsize+gridsize/2);
    cp1.setY((ui->frame->y/gridsize)*gridsize+gridsize/2);
}

void MainWindow::on_setcorner2_clicked()
{
    cp2.setX((ui->frame->x/gridsize)*gridsize+gridsize/2);
    cp2.setY((ui->frame->y/gridsize)*gridsize+gridsize/2);

    clipper_points[0][0]=cp1.x();
    clipper_points[0][1]=cp1.y();
    clipper_points[1][0]=cp1.x();
    clipper_points[1][1]=cp2.y();
    clipper_points[2][0]=cp2.x();
    clipper_points[2][1]=cp2.y();
    clipper_points[3][0]=cp2.x();
    clipper_points[3][1]=cp1.y();

    draw_Window();
}

void MainWindow::draw_Window()
{
    int r=ui->r_scroll_bar->value();
    int g=ui->g_scroll_bar->value();
    int b=ui->b_scroll_bar->value();

    p1.setX(clipper_points[0][0]);
    p1.setY(clipper_points[0][1]);
    p2.setX(clipper_points[1][0]);
    p2.setY(clipper_points[1][1]);
    DDAline(255-r,255-g,255-b);

    p1.setX(clipper_points[1][0]);
    p1.setY(clipper_points[1][1]);
    p2.setX(clipper_points[2][0]);
    p2.setY(clipper_points[2][1]);
    DDAline(255-r,255-g,255-b);

    p1.setX(clipper_points[2][0]);
    p1.setY(clipper_points[2][1]);
    p2.setX(clipper_points[3][0]);
    p2.setY(clipper_points[3][1]);
    DDAline(255-r,255-g,255-b);

    p1.setX(clipper_points[3][0]);
    p1.setY(clipper_points[3][1]);
    p2.setX(clipper_points[0][0]);
    p2.setY(clipper_points[0][1]);
    DDAline(255-r,255-g,255-b);
}

// ************************** LINE CLIPPING ********************************
// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000


// Function to compute region code for a point(x, y)
int MainWindow::computeCode(int xa, int ya)
{
    int x_min=cp1.x(),x_max=cp2.x(),y_min=cp1.y(),y_max=cp2.y();

    // initialized as being inside
        int code = INSIDE;
        if (xa < x_min)       // to the left of rectangle
            code |= LEFT;
        else if (xa > x_max)  // to the right of rectangle
            code |= RIGHT;
        if (ya < y_min)       // below the rectangle
            code |= BOTTOM;
        else if (ya > y_max)  // above the rectangle
            code |= TOP;

        return code;
}
// Implementing Cohen-Sutherland algorithm
// Clipping a line from P1 = (x2, y2) to P2 = (x2, y2)
void MainWindow::cohenSutherlandClip(int x1, int y1,int x2, int y2)
{
    int x_min=clipper_points[0][0],x_max=clipper_points[2][0],y_min=clipper_points[0][1],y_max=clipper_points[2][1];
    // Compute region codes for P1, P2
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    // Initialize line as outside the rectangular window
    bool accept = false;

    while (true)
    {

        if ((code1 == 0) && (code2 == 0))
        {
            // If both endpoints lie within rectangle
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            // If both endpoints are outside rectangle,
            // in same region
            break;
        }
        else
        {
            // Some segment of line lies within the
            // rectangle
            int code_out;
            int x, y;

            // At least one endpoint is outside the
            // rectangle, pick it.
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find intersection point;
            // using formulas y = y1 + slope * (x - x1),
            // x = x1 + (1 / slope) * (y - y1)
            if (code_out & TOP)
            {
                // point is above the clip rectangle
                x = x1 + (int)((double)(x2 - x1) *(double)(y_max - y1) /(double)(y2 - y1));
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                // point is below the rectangle
                x = x1 + (int)((double)(x2 - x1) * (double)(y_min - y1) / (double)(y2 - y1));
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                // point is to the right of rectangle
                y = y1 + (int)((double)(y2 - y1) * (double)(x_max - x1) / (double)(x2 - x1));
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                // point is to the left of rectangle
                y = y1 + (int)((double)(y2 - y1) * (double)(x_min - x1) / (double)(x2 - x1));
                x = x_min;
            }

            // Now intersection point x,y is found
            // We replace point outside rectangle
            // by intersection point
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        //If accepted
        //Just reset and draw the boundary and the line
        //Reset the screen and draw the grid

        p1.setX(x1);
        p1.setY(y1);

        p2.setX(x2);
        p2.setY(y2);

        int r=ui->r_scroll_bar->value();
        int g=ui->g_scroll_bar->value();
        int b=ui->b_scroll_bar->value();

        DDAline(r,g,b);
        draw_Window();
    }
    else
    {
        //If not accepted
        //Just reset and draw the boundary
        //Reset the screen and draw the grid
        draw_Window();
    }

}
void MainWindow::on_lineclipping_clicked()
{
    clock_t start, end;
    start = clock();

    DDAline(0,0,0);
    cohenSutherlandClip(p1.x(),p1.y(),p2.x(),p2.y());

    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    ui->lineClippinTImeTaken->setText("Time Taken : "+QString::number(time_taken,'g',6)+"s");
}
// *********************** POLYGON CLIPPING *************************************
const int MAX_POINTS = 20;

// Returns x-value of point of intersectipn of two
// lines
int MainWindow::x_intersect(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4)
{
    y1=ui->frame->height()-y1+1;
    y2=ui->frame->height()-y2+1;
    y3=ui->frame->height()-y3+1;
    y4=ui->frame->height()-y4+1;
    int num = (x1*y2 - y1*x2) * (x3-x4) -
              (x1-x2) * (x3*y4 - y3*x4);
    int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
    int retx=num/den;
    return retx;
}

// Returns y-value of point of intersectipn of
// two lines
int MainWindow:: y_intersect(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4)
{
    y1=ui->frame->height()-y1+1;
    y2=ui->frame->height()-y2+1;
    y3=ui->frame->height()-y3+1;
    y4=ui->frame->height()-y4+1;
    int num = (x1*y2 - y1*x2) * (y3-y4) -
              (y1-y2) * (x3*y4 - y3*x4);
    int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
    int rety= (ui->frame->height()-num/den+1);
    return rety;
}

// This functions clips all the edges w.r.t one clip
// edge of clipping area
void MainWindow:: clip(int x1, int y1, int x2, int y2)
{
    int poly_size=vertex_list.size()-1;
    int new_poly_size = 0;

    std::vector<std::pair<int,int> > new_points;

    // (ix,iy),(kx,ky) are the co-ordinate values of
    // the points
    for (int i = 0; i < poly_size; i++)
    {
        // i and k form a line in polygon
        int k = (i+1) % poly_size;
        int ix = vertex_list[i].first, iy = vertex_list[i].second;
        int kx = vertex_list[k].first, ky = vertex_list[k].second;

        // Calculating position of first and second point

        int i_pos,k_pos;
        if(x2==x1 && ix>x1) i_pos=1;
        else if(x2==x1 && ix<x1) i_pos=-1;
        else if(y2==y1 && iy<y1) i_pos=1;
        else i_pos=-1;

        if(x2==x1 && kx>x1) k_pos=1;
        else if(x2==x1 && kx<x1) k_pos=-1;
        else if(y2==y1 && ky<y1) k_pos=1;
        else k_pos=-1;

        if(y1>y2||x1>x2)
        {
            i_pos=(-1)*i_pos;
            k_pos=(-1)*k_pos;
        }

        // Case 1 : When both points are inside
        if (i_pos >= 0  && k_pos >= 0)
        {
            //Only second point is added
            new_points.push_back(std::make_pair(kx,ky));
            new_poly_size++;
        }

        // Case 2: When only first point is outside
        else if (i_pos < 0  && k_pos >= 0)
        {
            // Point of intersection with edge
            // and the second point is added

            new_points.push_back(std::make_pair(x_intersect(x1,y1, x2, y2, ix, iy, kx, ky),y_intersect(x1,y1, x2, y2, ix, iy, kx, ky)));
            new_poly_size++;

            new_points.push_back(std::make_pair(kx,ky));
            new_poly_size++;
        }

        // Case 3: When only second point is outside
        else if (i_pos >= 0  && k_pos < 0)
        {
            //Only point of intersection with edge is added

            new_points.push_back(std::make_pair(x_intersect(x1,y1, x2, y2, ix, iy, kx, ky),y_intersect(x1,y1, x2, y2, ix, iy, kx, ky)));
            new_poly_size++;
        }

        // Case 4: When both points are outside
        else
        {
            //No points are added
        }
    }

    // Copying new points into original array
    // and changing the no. of vertices
    poly_size = new_poly_size;
    vertex_list.clear();
    for (int i = 0; i < new_points.size(); i++)
    {
        vertex_list.push_back(new_points[i]);
    }
    vertex_list.push_back(new_points[0]);
}

// Implements Sutherland–Hodgman algorithm
void MainWindow::suthHodgClip()
{
    std::vector<std::pair<int,int> > old_vertex;
    for(int i=0;i<vertex_list.size();i++)
    {
        old_vertex.push_back(vertex_list[i]);
    }
    int clipper_size=4;
    //i and k are two consecutive indexes
    for (int i=0; i<clipper_size; i++)
    {
        int k = (i+1) % clipper_size;

        // We pass the current array of vertices, it's size
        // and the end points of the selected clipper line
        clip(clipper_points[i][0],
             clipper_points[i][1], clipper_points[k][0],
             clipper_points[k][1]);
    }
    int r=ui->r_scroll_bar->value();
    int g=ui->g_scroll_bar->value();
    int b=ui->b_scroll_bar->value();
    poly_draw(old_vertex,0,0,0);
    poly_draw(vertex_list,r,g,b);
    draw_Window();
}
void MainWindow::on_polygonclipping_clicked()
{
    clock_t start, end;
    start = clock();

    suthHodgClip();

    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    ui->polygonClippinTImeTaken->setText("Time Taken : "+QString::number(time_taken,'g',6)+"s");
}























































































std::vector<std::pair<int,int> > BezList;


void MainWindow::on_setbezpoint_clicked()
{
    int x=(ui->frame->x/gridsize)*gridsize+gridsize/2;
    int y=(ui->frame->y/gridsize)*gridsize+gridsize/2;
    BezList.push_back(std::make_pair(x,y));

    int i=BezList.size();

    if(BezList.size()>1)
    {
        storeEdgeInTable(BezList[i-2].first, BezList[i-2].second, BezList[i-1].first, BezList[i-1].second);//storage of edges in edge table.

        p1.setX(BezList[BezList.size()-1].first);
        p2.setX(BezList[BezList.size()-2].first);

        p1.setY(BezList[BezList.size()-1].second);
        p2.setY(BezList[BezList.size()-2].second);
        int r=ui->r_scroll_bar->value();
        int g=ui->g_scroll_bar->value();
        int b=ui->b_scroll_bar->value();
        DDAline(r,g,b);

    }
}








































































void MainWindow::on_clearbezpoint_clicked()
{
    BezList.clear();
}

void MainWindow::on_drawBezierCurve_clicked()
{
    clock_t start, end;
    start = clock();
    int r=ui->r_scroll_bar->value();
    int g=ui->g_scroll_bar->value();
    int b=ui->b_scroll_bar->value();

    double xu = 0.0 , yu = 0.0 , u = 0.0 ;
    int i =BezList.size();

    if(i==3){
        for(u = 0.0 ; u <= 1.0 ; u += 0.001)
            {
                xu = pow(1-u,2)*BezList[0].first + 2*u*(1-u)*BezList[1].first + pow(u,2)*BezList[2].first;
                yu = pow(1-u,2)*BezList[0].second + 2*u*(1-u)*BezList[1].second + pow(u,2)*BezList[2].second;
                point((int)xu , (int)yu,r,g,b) ;
                delay();
            }
    }
    else if(i==2){
        p1.setX(BezList[0].first);
        p2.setX(BezList[1].first);

        p1.setY(BezList[0].second);
        p2.setY(BezList[1].second);

        DDAline(r,g,b);
    }
    else if(i==4){
        for(u = 0.0 ; u <= 1.0 ; u += 0.001)
            {
                xu = pow(1-u,3)*BezList[0].first + 3*u*pow(1-u,2)*BezList[1].first + 3*pow(u,2)*(1-u)*BezList[2].first + pow(u,3)*BezList[3].first;
                yu = pow(1-u,3)*BezList[0].second + 3*u*pow(1-u,2)*BezList[1].second + 3*pow(u,2)*(1-u)*BezList[2].second + pow(u,3)*BezList[3].second;
                point((int)xu , (int)yu,r,g,b) ;
                delay();
            }
    }

    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    //ui->bezierCurveTimeTaken->setText("Time Taken : "+QString::number(time_taken,'g',6)+"s");
}
