#ifndef CLIENT_H
#define CLIENT_H

#include <QDataStream>
#include <QDialog>
#include <QTcpSocket>

#define CLIENT_SERVER 0
#define CLIENT_CLIENT 1

typedef std::pair<char *, int> buffer;

class Client : public QObject
{
	Q_OBJECT
	
public:
	explicit Client(int mode, QString server_v, int port_v, QWidget *parent = nullptr);
	~Client();
	void setConnection(QString server_v, int port_v);
	void close();
	void Connection();
public slots:
	void read();
	void writeData(void *data, size_t size);
	void audio();
	void readAudio();
private:
	QTcpSocket tcpSocket;
	QDataStream in;
	QString server;
	int port;
	int _bytes_left;
	std::vector <buffer> _buffers;
        char *_audio;
};

#endif
