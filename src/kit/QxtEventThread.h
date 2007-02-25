/*******************************************************************
Qt extended Library 
Copyright (C) 2007 Arvid Picciani <aep@exys.org>
released under the Terms of LGPL (see the LICENSE file)
*******************************************************************/

#include <QThread>

#include <Qxt/qxtglobal.h>
namespace QxtInternal{
class QxtThreadConnectionSender : public QObject
	{
	Q_OBJECT
	public:

		void connect( const QObject * sender, const char * signal, const char * method );
	signals:
		void connect_si( const QObject * sender, const char * signal, const char * method );
	};


class QxtThreadConnector : public QObject
	{
	Q_OBJECT
	public:
		QxtThreadConnector(QObject * t,QxtThreadConnectionSender * csender);

	private slots:
		void connect_sl( const QObject * sender, const char * signal, const char * method );

	private:
		QObject * t_t;
	};



class QxtEventThreadPrivate : public QThread
	{
	public:

		QxtEventThreadPrivate(QObject *parent=0);

		~QxtEventThreadPrivate();

		void connect ( const QObject * sender, const char * signal, const char * method ) const;

		void run();

		QxtInternal::QxtThreadConnector * connector;
		QxtInternal::QxtThreadConnectionSender * csender;

		virtual QObject * instance()const =0;


	};

}




template<typename T>
class QXT_KIT_EXPORT QxtEventThread : public QxtInternal::QxtEventThreadPrivate
	{
	public:
	QxtEventThread(QObject *parent=0):QxtEventThreadPrivate(parent)
		{
		instance_p=NULL;
		}

	QObject * instance() const {return instance_p;}

	void  run()
		{
 		T t;
 		instance_p = &t;
		QxtEventThreadPrivate::run();
		}

	T * instance_p;
	};
