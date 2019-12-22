#ifndef SLIDESHOW_H
#define SLIDESHOW_H

#include <QVector>

#include <memory>

class Slide;

class SlideShow
{
public:
    SlideShow(QString name)
      : mName(name)
    {}
    void addSlide(std::unique_ptr<Slide> slide);
private:
    QVector<std::unique_ptr<Slide>> mSlides;
    QString mName;
};

#endif // SLIDESHOW_H
