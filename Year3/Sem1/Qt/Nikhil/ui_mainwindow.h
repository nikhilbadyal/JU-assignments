/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    my_label *frame;
    QFrame *x_axis;
    QFrame *y_axis;
    QGroupBox *drawline;
    QPushButton *bresenhamLine;
    QPushButton *set_point2;
    QPushButton *set_point1;
    QPushButton *DDALine;
    QLabel *dda_time_taken;
    QLabel *bresenham_time_taken;
    QLabel *set_point_1_text;
    QLabel *set_point_2_text;
    QGroupBox *drawcircle;
    QSpinBox *radiusspinbox;
    QLabel *label_2;
    QPushButton *bresenhamCircle;
    QPushButton *midPointCircle;
    QLabel *mid_point_circle_time_taken;
    QLabel *bresenham_circle_time_taken;
    QLabel *label;
    QLabel *center_label_circle;
    QPushButton *polarCircle;
    QLabel *polar_circle_time_taken;
    QPushButton *pushButton;
    QLabel *parametric_circle_time_taken;
    QGroupBox *drawellipse;
    QSpinBox *r2spinbox;
    QSpinBox *r1spinbox;
    QLabel *label_7;
    QLabel *label_6;
    QPushButton *ellipse;
    QLabel *bresenham_ellipse_time_taken;
    QLabel *label_4;
    QLabel *center_label_ellipse;
    QGroupBox *groupBox;
    QCheckBox *show_axes;
    QPushButton *setgridbutton;
    QSpinBox *gridspinbox;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *mouse_pressed;
    QLabel *mouse_movement;
    QPushButton *resetButton;
    QGroupBox *filling;
    QPushButton *scanlinefill;
    QPushButton *floodfill;
    QPushButton *boundaryfill;
    QLabel *flood_fill_time_taken;
    QLabel *boundary_fill_time_taken;
    QLabel *scanline_fill_time_taken;
    QGroupBox *tranformation;
    QLabel *label_20;
    QSpinBox *xshear;
    QSpinBox *anglespinbox;
    QPushButton *shearing;
    QLabel *label_21;
    QSpinBox *yshear;
    QLabel *label_22;
    QSpinBox *xtranslate;
    QLabel *label_23;
    QLabel *label_24;
    QPushButton *scaling;
    QLabel *label_25;
    QLabel *label_26;
    QSpinBox *ytranslate;
    QPushButton *rotation;
    QPushButton *reflection;
    QPushButton *translation;
    QLabel *translation_time_taken;
    QLabel *scaling_time_taken;
    QLabel *rotation_time_taken;
    QLabel *shearing_time_taken;
    QLabel *reflection_time_taken;
    QDoubleSpinBox *xscale;
    QDoubleSpinBox *yscale;
    QGroupBox *groupBox_2;
    QLabel *rgb_mouse_movement;
    QLabel *color_frame;
    QLabel *label_15;
    QScrollBar *r_scroll_bar;
    QScrollBar *b_scroll_bar;
    QLabel *label_14;
    QScrollBar *g_scroll_bar;
    QLabel *label_13;
    QLabel *label_19;
    QLabel *fillcolor_rlabel;
    QLabel *label_18;
    QLabel *fillcolor_glabel;
    QLabel *fillcolor_blabel;
    QLabel *label_17;
    QLabel *label_8;
    QLabel *bvalue_label;
    QLabel *gvalue_label;
    QLabel *label_16;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *rvalue_label;
    QCheckBox *pickcolor_checkBox;
    QFrame *line;
    QGroupBox *groupBox_3;
    QPushButton *polygon_mode;
    QPushButton *setvertex;
    QPushButton *clearvertex;
    QGroupBox *clipping;
    QPushButton *lineclipping;
    QPushButton *setcorner1;
    QPushButton *setcorner2;
    QPushButton *polygonclipping;
    QLabel *lineClippinTImeTaken;
    QLabel *polygonClippinTImeTaken;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1080);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new my_label(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 1000, 1000));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(1);
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName(QString::fromUtf8("x_axis"));
        x_axis->setGeometry(QRect(10, 225, 1000, 1));
        x_axis->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName(QString::fromUtf8("y_axis"));
        y_axis->setGeometry(QRect(225, 10, 1, 1000));
        y_axis->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        drawline = new QGroupBox(centralWidget);
        drawline->setObjectName(QString::fromUtf8("drawline"));
        drawline->setGeometry(QRect(1200, 0, 241, 181));
        bresenhamLine = new QPushButton(drawline);
        bresenhamLine->setObjectName(QString::fromUtf8("bresenhamLine"));
        bresenhamLine->setGeometry(QRect(100, 100, 131, 31));
        set_point2 = new QPushButton(drawline);
        set_point2->setObjectName(QString::fromUtf8("set_point2"));
        set_point2->setGeometry(QRect(10, 100, 81, 31));
        set_point1 = new QPushButton(drawline);
        set_point1->setObjectName(QString::fromUtf8("set_point1"));
        set_point1->setGeometry(QRect(10, 20, 81, 31));
        DDALine = new QPushButton(drawline);
        DDALine->setObjectName(QString::fromUtf8("DDALine"));
        DDALine->setGeometry(QRect(100, 20, 131, 31));
        dda_time_taken = new QLabel(drawline);
        dda_time_taken->setObjectName(QString::fromUtf8("dda_time_taken"));
        dda_time_taken->setGeometry(QRect(100, 60, 131, 31));
        dda_time_taken->setFrameShape(QFrame::Panel);
        bresenham_time_taken = new QLabel(drawline);
        bresenham_time_taken->setObjectName(QString::fromUtf8("bresenham_time_taken"));
        bresenham_time_taken->setGeometry(QRect(100, 140, 131, 31));
        bresenham_time_taken->setFrameShape(QFrame::Panel);
        set_point_1_text = new QLabel(drawline);
        set_point_1_text->setObjectName(QString::fromUtf8("set_point_1_text"));
        set_point_1_text->setGeometry(QRect(10, 60, 81, 31));
        set_point_1_text->setFrameShape(QFrame::Box);
        set_point_1_text->setAlignment(Qt::AlignCenter);
        set_point_2_text = new QLabel(drawline);
        set_point_2_text->setObjectName(QString::fromUtf8("set_point_2_text"));
        set_point_2_text->setGeometry(QRect(10, 140, 81, 31));
        set_point_2_text->setFrameShape(QFrame::Box);
        set_point_2_text->setAlignment(Qt::AlignCenter);
        drawcircle = new QGroupBox(centralWidget);
        drawcircle->setObjectName(QString::fromUtf8("drawcircle"));
        drawcircle->setGeometry(QRect(1170, 180, 271, 221));
        radiusspinbox = new QSpinBox(drawcircle);
        radiusspinbox->setObjectName(QString::fromUtf8("radiusspinbox"));
        radiusspinbox->setGeometry(QRect(80, 20, 41, 21));
        label_2 = new QLabel(drawcircle);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 71, 21));
        bresenhamCircle = new QPushButton(drawcircle);
        bresenhamCircle->setObjectName(QString::fromUtf8("bresenhamCircle"));
        bresenhamCircle->setGeometry(QRect(10, 130, 111, 31));
        midPointCircle = new QPushButton(drawcircle);
        midPointCircle->setObjectName(QString::fromUtf8("midPointCircle"));
        midPointCircle->setGeometry(QRect(10, 90, 111, 31));
        mid_point_circle_time_taken = new QLabel(drawcircle);
        mid_point_circle_time_taken->setObjectName(QString::fromUtf8("mid_point_circle_time_taken"));
        mid_point_circle_time_taken->setGeometry(QRect(130, 90, 131, 31));
        mid_point_circle_time_taken->setFrameShape(QFrame::Panel);
        bresenham_circle_time_taken = new QLabel(drawcircle);
        bresenham_circle_time_taken->setObjectName(QString::fromUtf8("bresenham_circle_time_taken"));
        bresenham_circle_time_taken->setGeometry(QRect(130, 130, 131, 31));
        bresenham_circle_time_taken->setFrameShape(QFrame::Panel);
        label = new QLabel(drawcircle);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 20, 61, 20));
        center_label_circle = new QLabel(drawcircle);
        center_label_circle->setObjectName(QString::fromUtf8("center_label_circle"));
        center_label_circle->setGeometry(QRect(180, 20, 81, 20));
        center_label_circle->setFrameShape(QFrame::Box);
        polarCircle = new QPushButton(drawcircle);
        polarCircle->setObjectName(QString::fromUtf8("polarCircle"));
        polarCircle->setGeometry(QRect(10, 50, 111, 31));
        polar_circle_time_taken = new QLabel(drawcircle);
        polar_circle_time_taken->setObjectName(QString::fromUtf8("polar_circle_time_taken"));
        polar_circle_time_taken->setGeometry(QRect(130, 50, 131, 31));
        polar_circle_time_taken->setFrameShape(QFrame::Panel);
        pushButton = new QPushButton(drawcircle);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 170, 111, 31));
        parametric_circle_time_taken = new QLabel(drawcircle);
        parametric_circle_time_taken->setObjectName(QString::fromUtf8("parametric_circle_time_taken"));
        parametric_circle_time_taken->setGeometry(QRect(130, 170, 131, 31));
        parametric_circle_time_taken->setFrameShape(QFrame::Panel);
        drawellipse = new QGroupBox(centralWidget);
        drawellipse->setObjectName(QString::fromUtf8("drawellipse"));
        drawellipse->setGeometry(QRect(1020, 180, 141, 221));
        r2spinbox = new QSpinBox(drawellipse);
        r2spinbox->setObjectName(QString::fromUtf8("r2spinbox"));
        r2spinbox->setGeometry(QRect(10, 80, 121, 22));
        r1spinbox = new QSpinBox(drawellipse);
        r1spinbox->setObjectName(QString::fromUtf8("r1spinbox"));
        r1spinbox->setGeometry(QRect(10, 40, 121, 22));
        label_7 = new QLabel(drawellipse);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 60, 121, 20));
        label_6 = new QLabel(drawellipse);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 20, 121, 20));
        ellipse = new QPushButton(drawellipse);
        ellipse->setObjectName(QString::fromUtf8("ellipse"));
        ellipse->setGeometry(QRect(10, 140, 121, 31));
        bresenham_ellipse_time_taken = new QLabel(drawellipse);
        bresenham_ellipse_time_taken->setObjectName(QString::fromUtf8("bresenham_ellipse_time_taken"));
        bresenham_ellipse_time_taken->setGeometry(QRect(10, 180, 121, 31));
        bresenham_ellipse_time_taken->setFrameShape(QFrame::Panel);
        label_4 = new QLabel(drawellipse);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 110, 61, 20));
        center_label_ellipse = new QLabel(drawellipse);
        center_label_ellipse->setObjectName(QString::fromUtf8("center_label_ellipse"));
        center_label_ellipse->setGeometry(QRect(60, 110, 71, 20));
        center_label_ellipse->setFrameShape(QFrame::Box);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(1020, 0, 171, 181));
        show_axes = new QCheckBox(groupBox);
        show_axes->setObjectName(QString::fromUtf8("show_axes"));
        show_axes->setGeometry(QRect(10, 20, 101, 21));
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        font.setWeight(50);
        show_axes->setFont(font);
        setgridbutton = new QPushButton(groupBox);
        setgridbutton->setObjectName(QString::fromUtf8("setgridbutton"));
        setgridbutton->setGeometry(QRect(10, 50, 151, 23));
        gridspinbox = new QSpinBox(groupBox);
        gridspinbox->setObjectName(QString::fromUtf8("gridspinbox"));
        gridspinbox->setGeometry(QRect(120, 20, 41, 22));
        gridspinbox->setMinimum(1);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 120, 91, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 70, 121, 20));
        mouse_pressed = new QLabel(groupBox);
        mouse_pressed->setObjectName(QString::fromUtf8("mouse_pressed"));
        mouse_pressed->setGeometry(QRect(10, 140, 151, 31));
        mouse_pressed->setFrameShape(QFrame::Panel);
        mouse_movement = new QLabel(groupBox);
        mouse_movement->setObjectName(QString::fromUtf8("mouse_movement"));
        mouse_movement->setGeometry(QRect(10, 90, 151, 31));
        mouse_movement->setFrameShape(QFrame::Panel);
        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(1020, 960, 891, 31));
        QFont font1;
        font1.setPointSize(8);
        resetButton->setFont(font1);
        filling = new QGroupBox(centralWidget);
        filling->setObjectName(QString::fromUtf8("filling"));
        filling->setGeometry(QRect(1020, 410, 281, 141));
        scanlinefill = new QPushButton(filling);
        scanlinefill->setObjectName(QString::fromUtf8("scanlinefill"));
        scanlinefill->setGeometry(QRect(10, 100, 91, 31));
        floodfill = new QPushButton(filling);
        floodfill->setObjectName(QString::fromUtf8("floodfill"));
        floodfill->setGeometry(QRect(10, 20, 91, 31));
        boundaryfill = new QPushButton(filling);
        boundaryfill->setObjectName(QString::fromUtf8("boundaryfill"));
        boundaryfill->setGeometry(QRect(10, 60, 91, 31));
        flood_fill_time_taken = new QLabel(filling);
        flood_fill_time_taken->setObjectName(QString::fromUtf8("flood_fill_time_taken"));
        flood_fill_time_taken->setGeometry(QRect(110, 20, 161, 31));
        flood_fill_time_taken->setFrameShape(QFrame::Box);
        boundary_fill_time_taken = new QLabel(filling);
        boundary_fill_time_taken->setObjectName(QString::fromUtf8("boundary_fill_time_taken"));
        boundary_fill_time_taken->setGeometry(QRect(110, 60, 161, 31));
        boundary_fill_time_taken->setFrameShape(QFrame::Box);
        scanline_fill_time_taken = new QLabel(filling);
        scanline_fill_time_taken->setObjectName(QString::fromUtf8("scanline_fill_time_taken"));
        scanline_fill_time_taken->setGeometry(QRect(110, 100, 161, 31));
        scanline_fill_time_taken->setFrameShape(QFrame::Box);
        tranformation = new QGroupBox(centralWidget);
        tranformation->setObjectName(QString::fromUtf8("tranformation"));
        tranformation->setGeometry(QRect(1020, 550, 461, 221));
        label_20 = new QLabel(tranformation);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(200, 140, 21, 21));
        xshear = new QSpinBox(tranformation);
        xshear->setObjectName(QString::fromUtf8("xshear"));
        xshear->setGeometry(QRect(130, 140, 51, 22));
        xshear->setMinimum(-99);
        anglespinbox = new QSpinBox(tranformation);
        anglespinbox->setObjectName(QString::fromUtf8("anglespinbox"));
        anglespinbox->setGeometry(QRect(220, 100, 51, 22));
        anglespinbox->setMinimum(-999);
        anglespinbox->setValue(0);
        shearing = new QPushButton(tranformation);
        shearing->setObjectName(QString::fromUtf8("shearing"));
        shearing->setGeometry(QRect(10, 140, 91, 31));
        label_21 = new QLabel(tranformation);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(110, 140, 21, 21));
        yshear = new QSpinBox(tranformation);
        yshear->setObjectName(QString::fromUtf8("yshear"));
        yshear->setGeometry(QRect(220, 140, 51, 22));
        yshear->setMinimum(-99);
        label_22 = new QLabel(tranformation);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(200, 66, 21, 21));
        xtranslate = new QSpinBox(tranformation);
        xtranslate->setObjectName(QString::fromUtf8("xtranslate"));
        xtranslate->setGeometry(QRect(130, 25, 51, 21));
        xtranslate->setMinimum(-999);
        xtranslate->setMaximum(999);
        label_23 = new QLabel(tranformation);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(110, 66, 20, 20));
        label_24 = new QLabel(tranformation);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(110, 25, 20, 20));
        scaling = new QPushButton(tranformation);
        scaling->setObjectName(QString::fromUtf8("scaling"));
        scaling->setGeometry(QRect(10, 60, 91, 31));
        label_25 = new QLabel(tranformation);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(110, 100, 111, 21));
        label_26 = new QLabel(tranformation);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(200, 25, 16, 21));
        ytranslate = new QSpinBox(tranformation);
        ytranslate->setObjectName(QString::fromUtf8("ytranslate"));
        ytranslate->setGeometry(QRect(220, 25, 51, 22));
        ytranslate->setMinimum(-999);
        ytranslate->setMaximum(999);
        rotation = new QPushButton(tranformation);
        rotation->setObjectName(QString::fromUtf8("rotation"));
        rotation->setGeometry(QRect(10, 100, 91, 31));
        reflection = new QPushButton(tranformation);
        reflection->setObjectName(QString::fromUtf8("reflection"));
        reflection->setGeometry(QRect(10, 180, 91, 31));
        translation = new QPushButton(tranformation);
        translation->setObjectName(QString::fromUtf8("translation"));
        translation->setGeometry(QRect(10, 20, 91, 31));
        translation_time_taken = new QLabel(tranformation);
        translation_time_taken->setObjectName(QString::fromUtf8("translation_time_taken"));
        translation_time_taken->setGeometry(QRect(290, 20, 161, 31));
        translation_time_taken->setFrameShape(QFrame::Box);
        scaling_time_taken = new QLabel(tranformation);
        scaling_time_taken->setObjectName(QString::fromUtf8("scaling_time_taken"));
        scaling_time_taken->setGeometry(QRect(290, 60, 161, 31));
        scaling_time_taken->setFrameShape(QFrame::Box);
        rotation_time_taken = new QLabel(tranformation);
        rotation_time_taken->setObjectName(QString::fromUtf8("rotation_time_taken"));
        rotation_time_taken->setGeometry(QRect(290, 100, 161, 31));
        rotation_time_taken->setFrameShape(QFrame::Box);
        shearing_time_taken = new QLabel(tranformation);
        shearing_time_taken->setObjectName(QString::fromUtf8("shearing_time_taken"));
        shearing_time_taken->setGeometry(QRect(290, 140, 161, 31));
        shearing_time_taken->setFrameShape(QFrame::Box);
        reflection_time_taken = new QLabel(tranformation);
        reflection_time_taken->setObjectName(QString::fromUtf8("reflection_time_taken"));
        reflection_time_taken->setGeometry(QRect(290, 180, 161, 31));
        reflection_time_taken->setFrameShape(QFrame::Box);
        xscale = new QDoubleSpinBox(tranformation);
        xscale->setObjectName(QString::fromUtf8("xscale"));
        xscale->setGeometry(QRect(130, 66, 51, 22));
        xscale->setMinimum(-99.989999999999995);
        yscale = new QDoubleSpinBox(tranformation);
        yscale->setObjectName(QString::fromUtf8("yscale"));
        yscale->setGeometry(QRect(220, 66, 51, 22));
        yscale->setMinimum(-99.989999999999995);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(1470, 30, 371, 361));
        rgb_mouse_movement = new QLabel(groupBox_2);
        rgb_mouse_movement->setObjectName(QString::fromUtf8("rgb_mouse_movement"));
        rgb_mouse_movement->setGeometry(QRect(50, 290, 171, 31));
        rgb_mouse_movement->setFrameShape(QFrame::Box);
        rgb_mouse_movement->setAlignment(Qt::AlignCenter);
        color_frame = new QLabel(groupBox_2);
        color_frame->setObjectName(QString::fromUtf8("color_frame"));
        color_frame->setGeometry(QRect(40, 20, 100, 100));
        color_frame->setFrameShape(QFrame::Box);
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(210, 120, 10, 20));
        r_scroll_bar = new QScrollBar(groupBox_2);
        r_scroll_bar->setObjectName(QString::fromUtf8("r_scroll_bar"));
        r_scroll_bar->setGeometry(QRect(150, 10, 10, 100));
        r_scroll_bar->setMaximum(255);
        r_scroll_bar->setOrientation(Qt::Vertical);
        b_scroll_bar = new QScrollBar(groupBox_2);
        b_scroll_bar->setObjectName(QString::fromUtf8("b_scroll_bar"));
        b_scroll_bar->setGeometry(QRect(210, 10, 10, 100));
        b_scroll_bar->setMaximum(255);
        b_scroll_bar->setOrientation(Qt::Vertical);
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(170, 120, 16, 20));
        g_scroll_bar = new QScrollBar(groupBox_2);
        g_scroll_bar->setObjectName(QString::fromUtf8("g_scroll_bar"));
        g_scroll_bar->setGeometry(QRect(180, 10, 10, 100));
        g_scroll_bar->setMaximum(255);
        g_scroll_bar->setOrientation(Qt::Vertical);
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(150, 120, 10, 20));
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(160, 250, 20, 20));
        fillcolor_rlabel = new QLabel(groupBox_2);
        fillcolor_rlabel->setObjectName(QString::fromUtf8("fillcolor_rlabel"));
        fillcolor_rlabel->setGeometry(QRect(180, 180, 55, 21));
        fillcolor_rlabel->setFrameShape(QFrame::Box);
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(160, 210, 20, 20));
        fillcolor_glabel = new QLabel(groupBox_2);
        fillcolor_glabel->setObjectName(QString::fromUtf8("fillcolor_glabel"));
        fillcolor_glabel->setGeometry(QRect(180, 210, 55, 21));
        fillcolor_glabel->setFrameShape(QFrame::Box);
        fillcolor_blabel = new QLabel(groupBox_2);
        fillcolor_blabel->setObjectName(QString::fromUtf8("fillcolor_blabel"));
        fillcolor_blabel->setGeometry(QRect(180, 250, 55, 21));
        fillcolor_blabel->setFrameShape(QFrame::Box);
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(160, 180, 20, 20));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(160, 140, 91, 20));
        bvalue_label = new QLabel(groupBox_2);
        bvalue_label->setObjectName(QString::fromUtf8("bvalue_label"));
        bvalue_label->setGeometry(QRect(80, 250, 55, 21));
        bvalue_label->setFrameShape(QFrame::Box);
        gvalue_label = new QLabel(groupBox_2);
        gvalue_label->setObjectName(QString::fromUtf8("gvalue_label"));
        gvalue_label->setGeometry(QRect(80, 220, 55, 21));
        gvalue_label->setFrameShape(QFrame::Box);
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(50, 250, 20, 20));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(50, 180, 20, 20));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(50, 220, 20, 20));
        rvalue_label = new QLabel(groupBox_2);
        rvalue_label->setObjectName(QString::fromUtf8("rvalue_label"));
        rvalue_label->setGeometry(QRect(80, 180, 55, 21));
        rvalue_label->setFrameShape(QFrame::Box);
        pickcolor_checkBox = new QCheckBox(groupBox_2);
        pickcolor_checkBox->setObjectName(QString::fromUtf8("pickcolor_checkBox"));
        pickcolor_checkBox->setGeometry(QRect(40, 140, 91, 20));
        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(150, 150, 10, 121));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(1310, 410, 131, 141));
        polygon_mode = new QPushButton(groupBox_3);
        polygon_mode->setObjectName(QString::fromUtf8("polygon_mode"));
        polygon_mode->setGeometry(QRect(10, 20, 111, 31));
        setvertex = new QPushButton(groupBox_3);
        setvertex->setObjectName(QString::fromUtf8("setvertex"));
        setvertex->setGeometry(QRect(10, 60, 111, 31));
        clearvertex = new QPushButton(groupBox_3);
        clearvertex->setObjectName(QString::fromUtf8("clearvertex"));
        clearvertex->setGeometry(QRect(10, 100, 111, 31));
        clipping = new QGroupBox(centralWidget);
        clipping->setObjectName(QString::fromUtf8("clipping"));
        clipping->setGeometry(QRect(1030, 800, 421, 131));
        lineclipping = new QPushButton(clipping);
        lineclipping->setObjectName(QString::fromUtf8("lineclipping"));
        lineclipping->setGeometry(QRect(130, 50, 121, 31));
        setcorner1 = new QPushButton(clipping);
        setcorner1->setObjectName(QString::fromUtf8("setcorner1"));
        setcorner1->setGeometry(QRect(10, 50, 101, 31));
        setcorner2 = new QPushButton(clipping);
        setcorner2->setObjectName(QString::fromUtf8("setcorner2"));
        setcorner2->setGeometry(QRect(10, 90, 101, 31));
        polygonclipping = new QPushButton(clipping);
        polygonclipping->setObjectName(QString::fromUtf8("polygonclipping"));
        polygonclipping->setGeometry(QRect(130, 90, 121, 31));
        lineClippinTImeTaken = new QLabel(clipping);
        lineClippinTImeTaken->setObjectName(QString::fromUtf8("lineClippinTImeTaken"));
        lineClippinTImeTaken->setGeometry(QRect(260, 50, 151, 31));
        lineClippinTImeTaken->setFrameShape(QFrame::Box);
        polygonClippinTImeTaken = new QLabel(clipping);
        polygonClippinTImeTaken->setObjectName(QString::fromUtf8("polygonClippinTImeTaken"));
        polygonClippinTImeTaken->setGeometry(QRect(260, 90, 151, 31));
        polygonClippinTImeTaken->setFrameShape(QFrame::Box);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1920, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        frame->setText(QString());
        drawline->setTitle(QApplication::translate("MainWindow", "Line", nullptr));
        bresenhamLine->setText(QApplication::translate("MainWindow", "Bresenham Algorithm", nullptr));
        set_point2->setText(QApplication::translate("MainWindow", "Set point 2", nullptr));
        set_point1->setText(QApplication::translate("MainWindow", "Set point 1", nullptr));
        DDALine->setText(QApplication::translate("MainWindow", "DDA Algorithm", nullptr));
        dda_time_taken->setText(QString());
        bresenham_time_taken->setText(QString());
        set_point_1_text->setText(QString());
        set_point_2_text->setText(QString());
        drawcircle->setTitle(QApplication::translate("MainWindow", "Circle", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Set Radius", nullptr));
        bresenhamCircle->setText(QApplication::translate("MainWindow", "Bresenham Circle", nullptr));
        midPointCircle->setText(QApplication::translate("MainWindow", "Mid Point Circle", nullptr));
        mid_point_circle_time_taken->setText(QString());
        bresenham_circle_time_taken->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Center", nullptr));
        center_label_circle->setText(QString());
        polarCircle->setText(QApplication::translate("MainWindow", "Polar Circle", nullptr));
        polar_circle_time_taken->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Parametric Circle", nullptr));
        parametric_circle_time_taken->setText(QString());
        drawellipse->setTitle(QApplication::translate("MainWindow", "Ellpse", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Set Semi-Minor Axis", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Set Semi-Major Axis ", nullptr));
        ellipse->setText(QApplication::translate("MainWindow", "Draw Ellipse", nullptr));
        bresenham_ellipse_time_taken->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Center", nullptr));
        center_label_ellipse->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Screen", nullptr));
        show_axes->setText(QApplication::translate("MainWindow", "Show Axes", nullptr));
        setgridbutton->setText(QApplication::translate("MainWindow", "Set Grid", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Mouse Pressed", nullptr));
        label_3->setText(QApplication::translate("MainWindow", " Mouse Movement", nullptr));
        mouse_pressed->setText(QString());
        mouse_movement->setText(QString());
        resetButton->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        filling->setTitle(QApplication::translate("MainWindow", "Filling Algorithms", nullptr));
        scanlinefill->setText(QApplication::translate("MainWindow", "Scanline Fill", nullptr));
        floodfill->setText(QApplication::translate("MainWindow", "Flood Fill", nullptr));
        boundaryfill->setText(QApplication::translate("MainWindow", "Boundary Fill", nullptr));
        flood_fill_time_taken->setText(QString());
        boundary_fill_time_taken->setText(QString());
        scanline_fill_time_taken->setText(QString());
        tranformation->setTitle(QApplication::translate("MainWindow", "Transformation", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "y:", nullptr));
        shearing->setText(QApplication::translate("MainWindow", "Shearing", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "x:", nullptr));
        scaling->setText(QApplication::translate("MainWindow", "Scaling", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "angle in degrees : ", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "y:", nullptr));
        rotation->setText(QApplication::translate("MainWindow", "Rotation", nullptr));
        reflection->setText(QApplication::translate("MainWindow", "Reflection", nullptr));
        translation->setText(QApplication::translate("MainWindow", "Translation", nullptr));
        translation_time_taken->setText(QString());
        scaling_time_taken->setText(QString());
        rotation_time_taken->setText(QString());
        shearing_time_taken->setText(QString());
        reflection_time_taken->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Color", nullptr));
        rgb_mouse_movement->setText(QString());
        color_frame->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "B", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "G", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "R", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "B :", nullptr));
        fillcolor_rlabel->setText(QString());
        label_18->setText(QApplication::translate("MainWindow", "G :", nullptr));
        fillcolor_glabel->setText(QString());
        fillcolor_blabel->setText(QString());
        label_17->setText(QApplication::translate("MainWindow", "R :", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Current Color :", nullptr));
        bvalue_label->setText(QString());
        gvalue_label->setText(QString());
        label_16->setText(QApplication::translate("MainWindow", "B :", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "R :", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "G :", nullptr));
        rvalue_label->setText(QString());
        pickcolor_checkBox->setText(QApplication::translate("MainWindow", "Pick Color", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Polygon", nullptr));
        polygon_mode->setText(QApplication::translate("MainWindow", "Polygon (Un-Set)", nullptr));
        setvertex->setText(QApplication::translate("MainWindow", "Set vertex", nullptr));
        clearvertex->setText(QApplication::translate("MainWindow", "Clear vertex", nullptr));
        clipping->setTitle(QApplication::translate("MainWindow", "Clipping", nullptr));
        lineclipping->setText(QApplication::translate("MainWindow", "Line clipping", nullptr));
        setcorner1->setText(QApplication::translate("MainWindow", "Set Corner 1", nullptr));
        setcorner2->setText(QApplication::translate("MainWindow", "Set Corner 2", nullptr));
        polygonclipping->setText(QApplication::translate("MainWindow", "Polygon clipping", nullptr));
        lineClippinTImeTaken->setText(QString());
        polygonClippinTImeTaken->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
