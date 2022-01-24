// 함수 오버로딩을 통한 간략화

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
	Message(int sendTime, string sendName) {
		this->sendTime = sendTime;
		this->sendName = sendName;
	}
	int GetSendTime() const { return sendTime; }
	string GetSendName() const { return sendName; }

private:
	int sendTime;
	string sendName;
};

class TextMessage : public Message {
public:
	TextMessage(int sendTime, string sendName, string text)
		: Message(sendTime, sendName) {
		this->text = text;
	}

	string GetText() const { return text; }

private:
	string text;
};

class ImageMessage : public Message {
public:
	ImageMessage(int sendTime, string sendName, Image *image)
		: Message(sendTime, sendName) {
		this->image = image;
	}

	Image *GetImage() const { return image; }

private:
	int sendTime;
	string sendName;
	Image *image;
};

// 오버로딩을 통해 간략하게 만들기
void printMessage(TextMessage *m) {
	cout << "보낸 시간 : " << m->GetSendTime() << endl;
	cout << "보낸 사람 : " << m->GetSendName() << endl;
	cout << "  내 용   : " << m->GetText() << endl;
	cout << endl;
}

void printMessage(ImageMessage *m) {
	cout << "보낸 시간 : " << m->GetSendTime() << endl;
	cout << "보낸 사람 : " << m->GetSendName() << endl;
	cout << "  내 용   : " << (string)*m->GetImage() << endl;
	cout << endl;
}

int main() {
	Image *p_dogImage = new Image();
	TextMessage *hello = new TextMessage(10, "이", "안녕");
	ImageMessage *dog = new ImageMessage(20, "이", p_dogImage);

	printMessage(hello);
	printMessage(dog);

	delete hello;
	delete dog;
	delete p_dogImage;
}