#include "qwbattery.h"
#include "qwbatteryplugin.h"

#include <QtPlugin>

QwBatteryPlugin::QwBatteryPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QwBatteryPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool QwBatteryPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QwBatteryPlugin::createWidget(QWidget *parent)
{
    return new QwBattery(parent);
}

QString QwBatteryPlugin::name() const
{
    return QLatin1String("QwBattery"); // 自定义Widget 组件类的名称
}

QString QwBatteryPlugin::group() const
{
    return QLatin1String("My widget"); //　在组件面板中所属　分组名称
}

QIcon QwBatteryPlugin::icon() const
{
    return QIcon(); //　图标的文件名
}

QString QwBatteryPlugin::toolTip() const
{
    return QLatin1String("toolTip 信息"); // toolTip 信息
}

QString QwBatteryPlugin::whatsThis() const
{
    return QLatin1String("whatsThis 信息");
}

bool QwBatteryPlugin::isContainer() const
{
    return false; // 是否作为容器 false 表示该组件上不允许再放其他的组件
}

QString QwBatteryPlugin::domXml() const
{ // xml 文件描述信息
    return QLatin1String("<widget class=\"QwBattery\" name=\"qwBattery\">\n</widget>\n");
}

QString QwBatteryPlugin::includeFile() const
{ // 包含的文件名
    return QLatin1String("qwbattery.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(qwbatteryplugin, QwBatteryPlugin)
#endif // QT_VERSION < 0x050000
