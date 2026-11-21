#include<iostream>
#include<string>
using namespace std;
class User
{
private:
	string Username;
	string Password;
	int FailedAttempts;
public:
	User(string U, string P)
	{
		Username = U;
		Password = P;
		FailedAttempts = 0;

	}

	void DisplayUsername()
	{
		cout << "Your name is :" << Username << endl;
	}

	bool Login(string U, string P)

	{
		if (FailedAttempts >= 3)
		{
			cout << "Account Locked!\n";
			return false;
		}
		if (U == Username && P == Password)
		{
			FailedAttempts = 0;
			return true;
		}
		FailedAttempts++;
		if (FailedAttempts >= 3)
		{
			cout << "Account Locked!\n";
			return false;
		}

		return false;
	}

};


class Admin : public User
{
private:
	int AdminID;
public:
	Admin(string U, string P, int id):User(U,P)
	{
		AdminID = id;
	}


	void DisplayInfo()
	{
		DisplayUsername();
		cout << "Admin ID:" << AdminID << endl;
	}
};
int main()
{
	string Username;
	string Password;

	cout << "\n===== USER REGISTRATION =====\n";

	cout << "Create Username\n";
	cin >> Username;

	cout << "Create Password\n";
	cin >> Password;
	User u1(Username, Password);

	cout << "\n===== USER LOGIN =====\n";

	for (int i = 0; i < 3; i++)
	{
		cout << "Enter Username\n";
		cin >> Username;

		cout << "Enter Password\n";
		cin >> Password;

		if (u1.Login(Username, Password))
		{
			cout << "Login Successful\n";
			u1.DisplayUsername();
			break;
		}
		else
		{
			cout << "Login Failed\n";
		}
	}

	

	Admin a1("Ali", "Ali@1234", 101);

	cout << "\n===== ADMIN LOGIN =====\n";

	for (int i = 0; i < 3; i++)
	{
		cout << "Enter Username\n";
		cin >> Username;

		cout << "Enter Password\n";
		cin >> Password;

		if (a1.Login(Username, Password))
		{
			cout << "Admin Login Successful\n";
			a1.DisplayInfo();
			break;
		}
		else
		{
			cout << "Login Failed\n";
		}
	}

	

}
