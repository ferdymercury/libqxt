/****************************************************************************
**
** Copyright (C) Qxt Foundation. Some rights reserved.
**
** This file is part of the QxtWeb  module of the Qxt library.
**
** This library is free software; you can redistribute it and/or modify it
** under the terms of the Common Public License, version 1.0, as published by
** IBM.
**
** This file is provided "AS IS", without WARRANTIES OR CONDITIONS OF ANY
** KIND, EITHER EXPRESS OR IMPLIED INCLUDING, WITHOUT LIMITATION, ANY
** WARRANTIES OR CONDITIONS OF TITLE, NON-INFRINGEMENT, MERCHANTABILITY OR
** FITNESS FOR A PARTICULAR PURPOSE.
**
** You should have received a copy of the CPL along with this file.
** See the LICENSE file and the cpl1.0.txt file included with the source
** distribution for more information. If you did not receive a copy of the
** license, contact the Qxt Foundation.
**
** <http://www.libqxt.org>  <foundation@libqxt.org>
**
****************************************************************************/

#ifndef QXTABSTRACTWEBSESSIONMANAGER_H
#define QXTABSTRACTWEBSESSIONMANAGER_H

#include <QObject>
#include <qxtpimpl.h>
class QxtAbstractWebService;
class QxtWebEvent;

class QxtAbstractWebSessionManagerPrivate;
class QxtAbstractWebSessionManager : public QObject {
Q_OBJECT
public:
    typedef QxtAbstractWebService* ServiceFactory(QxtAbstractWebSessionManager*, int);

    QxtAbstractWebSessionManager(QObject* parent = 0);

    virtual bool start() = 0;
    virtual void postEvent(QxtWebEvent* event) = 0;
    void setServiceFactory(ServiceFactory* factory);
    ServiceFactory* serviceFactory() const;

    QxtAbstractWebService* session(int sessionID) const;

protected:
    int createService();

protected slots:
    virtual void processEvents() = 0;

private:
    QXT_DECLARE_PRIVATE(QxtAbstractWebSessionManager);
};

#endif
