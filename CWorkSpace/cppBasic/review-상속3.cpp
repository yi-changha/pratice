//상속

#include <iostream>
#include <string>
using namespace std;

class Image {
public:
	operator string() {
		return "사진";
	}
};

class Message {
public:
	Message(int sendTime, string sendName)
		: sendTime(sendTime), sendName(sendName) {}

	int GetSendTime() const { return sendTime; }
	string GetSendName() const { return sendName; }
	virtual string GetContent() const { return ""; }

private:
	int sendTime;
	string sendName;
};

class TextMessage : public Message {
public:
	TextMessage(int sendTime, string sendName, string text)
		: Message(sendTime, sendName), text(text) {}

	string GetText() const { return text; }
	string GetContent() const { return text; }

private:
	string text;
};

class ImageMessage : public Message {
public:
	ImageMessage(int sendTime, string sendName, Image *image)
		: Message(sendTime, sendName), p_image(image) {}

	Image *GetImage() const { return p_image; }
	string GetContent() const { return (string)*p_image; }

private:
	Image *p_image;
};

void printMessage(Message *m) {
	cout << "보낸 시간 : " << m->GetSendTime() << endl;
	cout << "보낸 사람 : " << m->GetSendName() << endl;
	cout << "  내 용   : " << m->GetContent() << endl;
	cout << endl;
}


int main() {
	Image *p_dogImage = new Image();

	Message *messages[] = {
		new TextMessage(10, "구글", "안녕"),
		new TextMessage(11, "구글", "안녕"),
		new TextMessage(12, "구글", "안녕"),
		new ImageMessage(20, "구글", p_dogImage)
	};

	for(Message *m : messages) {
		printMessage(m);
	}

	delete p_dogImage;
}