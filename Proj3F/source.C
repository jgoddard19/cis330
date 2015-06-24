#include "image.h"
#include "source.h"
#include "logging.h"

Image * source::GetOutput()
{
    return &image;
}

source::source()
{
    image.setSource(this);
};