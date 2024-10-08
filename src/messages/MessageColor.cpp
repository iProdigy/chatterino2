#include "messages/MessageColor.hpp"

#include "singletons/Theme.hpp"

namespace chatterino {

MessageColor::MessageColor(const QColor &color)
    : type_(Type::Custom)
    , customColor_(color)
{
}

MessageColor::MessageColor(Type type)
    : type_(type)
{
}

const QColor &MessageColor::getColor(Theme &themeManager) const
{
    switch (this->type_)
    {
        case Type::Custom:
            return this->customColor_;
        case Type::Text:
            return themeManager.messages.textColors.regular;
        case Type::System:
            return themeManager.messages.textColors.system;
        case Type::Link:
            return themeManager.messages.textColors.link;
    }

    static QColor _default;
    return _default;
}

QString MessageColor::toString() const
{
    switch (this->type_)
    {
        case Type::Custom:
            return this->customColor_.name(QColor::HexArgb);
        case Type::Text:
            return QStringLiteral("Text");
        case Type::System:
            return QStringLiteral("System");
        case Type::Link:
            return QStringLiteral("Link");
        default:
            return {};
    }
}

}  // namespace chatterino
