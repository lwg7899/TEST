#include "MouseEvent.h"

MouseEvent::MouseEvent():x(0),y(0){}

MouseEvent::MouseEvent(const EventType type, const int x, const int y) :type(type), x(x), y(y){}

bool MouseEvent::IsValid() const
{
    return this->type != EventType::Invalid;
}

MouseEvent::EventType MouseEvent::GetType() const
{
    return this->type;
}

MousePoint MouseEvent::GetPos() const
{
    return {this->x, this->y};
}

int MouseEvent::GetPosX() const
{
    return this->x;
}

int MouseEvent::GetPosY() const
{
    return this->y;
}