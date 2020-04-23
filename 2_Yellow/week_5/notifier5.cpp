#include <iostream>
#include <string>
using namespace std;


class INotifier{
public:  
  virtual void Notify(const string& message) =0;
};

void SendSms(const string& number, const string& message);
void SendEmail(const string& email, const string& message);

class SmsNotifier : public INotifier {
public:
  SmsNotifier(string number){
    phone_number = number;
  }
  void Notify(const string& message) override{
    SendSms(phone_number, message);
  }
private:
  string phone_number;
};


class EmailNotifier : public INotifier{
public:
  EmailNotifier (string email){
    email_adress = email;
  }
  void Notify(const string& message) override{
    SendEmail(email_adress, message);
  }
private:
  string email_adress;
};
/*
void SendSms(const string& number, const string& message) {
  cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message) {
  cout << "Send '" << message << "' to e-mail "  << email << endl;
}



void Notify(INotifier& notifier, const string& message) {
  notifier.Notify(message);
}


int main() {
  SmsNotifier sms{"+7-495-777-77-77"};
  EmailNotifier email{"na-derevnyu@dedushke.ru"};

  Notify(sms, "I have White belt in C++");
  Notify(email, "And want a Yellow one");
  return 0;
} */