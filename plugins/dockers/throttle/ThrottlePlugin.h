/*
 *  SPDX-FileCopyrightText: 2017 Boudewijn Rempt <boud@valdyas.org>
 *
 *  SPDX-License-Identifier: LGPL-2.0-or-later
 */

#ifndef THROTTLEPLUGIN_H
#define THROTTLEPLUGIN_H

#include <KisActionPlugin.h>

#include <QVariant>
#include <kddockwidgets/DockWidget.h>
#include <klocalizedstring.h>
#include <KoCanvasObserverBase.h>

class Throttle;

class BasicDocker : public KDDockWidgets::DockWidget, public KoCanvasObserverBase
{
    Q_OBJECT
public:
    BasicDocker() : KDDockWidgets::DockWidget(i18n("CPU Throttle")) {}
    ~BasicDocker() override {}
    QString observerName() override { return "ThrottleDocker"; }
    void setCanvas(KoCanvasBase *) override {}
    void unsetCanvas() override {}
};

class ThrottlePlugin : public QObject
{
    Q_OBJECT
public:
    ThrottlePlugin(QObject *parent, const QVariantList &);
    ~ThrottlePlugin() override;
};

#endif
