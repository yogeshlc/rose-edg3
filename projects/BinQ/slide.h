#ifndef CANNONFIELD_H
#define CANNONFIELD_H

#include <rose.h>
#include <QWidget>

#include "Item.h"
#include "BinQGui.h"
//class BinQGUI;
#include <qobject.h>

class Slide : public QWidget
{

 public:
  Slide(BinQGUI* gui, QWidget *parent = 0);
  ~Slide(){};
  void colorize();
  int maxX;
  int offset;
  void updateMouse();
 
 signals:
  void valueChanged(int value);

  public slots:
    void setValue(int value) ;
  
 protected:
  void paintEvent(QPaintEvent *event);
  void mouseMoveEvent( QMouseEvent *mevt );

 private:
    Q_OBJECT // cant get this to work
  
 private:

  int posX;
  int posY;
  BinQGUI* gui;
  QString lastStringA;
  int lastRowA;
  QString lastStringB;
  int lastRowB;
};

#endif
