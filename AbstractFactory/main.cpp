#include <iostream>
#include <string>

class Example {
public:
	virtual void Execute() = 0;
};
class Example_1_No_Pattern : public Example {
public:
	class User {
	public:
		std::string name;
		int id;
	};
	class A_ServerUser {
	public:
		void Insert(User *user) {
			std::cout << "Add user into A_Server.\n";
		}
		void QueryUser(int id) {
			std::cout << "Query user name via id in A_server.\n";
		}
	};
	class B_ServerUser {
	public:
		void Insert(User *user) {
			std::cout << "Add user into B_Server.\n";
		}
		void QueryUser(int id) {
			std::cout << "Query user name via id in B_server.\n";
		}
	};

	// Client end.
	void Execute() {

		User *user = new User;

		//A_ServerUser *a_su = new A_ServerUser;
		//a_su->Insert(user);
		//a_su->QueryUser(0);

		B_ServerUser *b_su = new B_ServerUser;
		b_su->Insert(user);
		b_su->QueryUser(0);

		delete user, b_su;
	}
};
class Example_2_Factory_Pattern : public Example {
public:
	class User {
	public:
		std::string name;
		int id;
	};

	// Operation(User) Interface
	class ServerUser {
	public:
		virtual void Insert(User *user) = 0;
		virtual void QueryUser(int id) = 0;
	};
	// Concrete Operation(User)
	class A_ServerUser : public ServerUser {
	public:
		void Insert(User *user) {
			std::cout << "Add user into A_Server.\n";
		}
		void QueryUser(int id) {
			std::cout << "Query user name via id in A_server.\n";
		}
	};
	class B_ServerUser : public ServerUser {
	public:
		void Insert(User *user) {
			std::cout << "Add user into B_Server.\n";
		}
		void QueryUser(int id) {
			std::cout << "Query user name via id in B_server.\n";
		}
	};

	// Factory Interface
	class ServerUserFactory {
	public:
		virtual ServerUser* CreateServerUser() = 0;
	};
	// Concrete Factory
	class A_ServerUserFactory : public ServerUserFactory {
	public:
		ServerUser* CreateServerUser() {
			return new A_ServerUser;
		}
	};
	class B_ServerUserFactory : public ServerUserFactory {
	public:
		ServerUser* CreateServerUser() {
			return new B_ServerUser;
		}
	};

	// Client end.
	void Execute() {

		User *user = new User;

		// The only statement needs to change when using B_ServerUser.
		ServerUserFactory *f = new A_ServerUserFactory; 

		ServerUser *su = f->CreateServerUser();

		su->Insert(user);
		su->QueryUser(0);

		delete user, f, su;
	}
};
class Example_3_Abstract_Pattern : public Example {
public:
	// If we have another operation (data) needs to add into server.
	class User {
	public:
		std::string name;
		int id;
	};
	class Department  {
	public:
		std::string name;
		int id;
	};

	// Operation(User) Interface
	class ServerUser {
	public:
		virtual void Insert(User *user) = 0;
		virtual void QueryUser(int id) = 0;
	};
	// Concrete Operation(User)
	class A_ServerUser : public ServerUser {
	public:
		void Insert(User *user) {
			std::cout << "Add user into A_Server.\n";
		}
		void QueryUser(int id) {
			std::cout << "Query user name via id in A_server.\n";
		}
	};
	class B_ServerUser : public ServerUser {
	public:
		void Insert(User *user) {
			std::cout << "Add user into B_Server.\n";
		}
		void QueryUser(int id) {
			std::cout << "Query user name via id in B_server.\n";
		}
	};

	// Operation(Department) Interface
	class ServerDepartment {
	public:
		virtual void Insert(Department *department) = 0;
		virtual void QueryDepartment(int id) = 0;
	};
	// Concrete Operation(Department)
	class A_ServerDepartment : public ServerDepartment {
	public:
		void Insert(Department *department) {
			std::cout << "Add department into A_Server.\n";
		}
		void QueryDepartment(int id) {
			std::cout << "Query department name via id in A_server.\n";
		}
	};
	class B_ServerDepartment : public ServerDepartment {
	public:
		void Insert(Department *department) {
			std::cout << "Add department into B_Server.\n";
		}
		void QueryDepartment(int id) {
			std::cout << "Query department name via id in B_server.\n";
		}
	};

	// Factory Interface
	class ServerFactory {
	public:
		virtual ServerUser* CreateServerUser() = 0;
		virtual ServerDepartment* CreateServerDepartment() = 0;
	};
	// Concrete Factory
	class A_ServerFactory : public ServerFactory {
	public:
		ServerUser * CreateServerUser() {
			return new A_ServerUser;
		}
		ServerDepartment * CreateServerDepartment() {
			return new A_ServerDepartment;
		}
	};
	class B_ServerFactory : public ServerFactory {
	public:
		ServerUser * CreateServerUser() {
			return new B_ServerUser;
		}
		ServerDepartment * CreateServerDepartment() {
			return new B_ServerDepartment;
		}
	};

	// Client end.
	void Execute() {

		// Assume there are two operations need to be added into server.
		User *user = new User;
		Department *department = new Department;

		// The only statement needs to change when using B_ServerUser.
		ServerFactory *f = new B_ServerFactory;

		ServerUser *su = f->CreateServerUser();
		su->Insert(user);
		su->QueryUser(0);

		ServerDepartment *sd = f->CreateServerDepartment();
		sd->Insert(department);
		sd->QueryDepartment(0);

		delete user, department, f, su, sd;
	}
};
class Example_4_Simple_Factory : public Example {
public:

	class User {
	public:
		std::string name;
		int id;
	};

	class Department {
	public:
		std::string name;
		int id;
	};

	// Operation(User) Interface
	class ServerUser {
	public:
		virtual void Insert(User *user) = 0;
		virtual void QueryUser(int id) = 0;
	};
	// Concrete Operation(User)
	class A_ServerUser : public ServerUser {
	public:
		void Insert(User *user) {
			std::cout << "Add user into A_Server.\n";
		}
		void QueryUser(int id) {
			std::cout << "Query user name via id in A_server.\n";
		}
	};
	class B_ServerUser : public ServerUser {
	public:
		void Insert(User *user) {
			std::cout << "Add user into B_Server.\n";
		}
		void QueryUser(int id) {
			std::cout << "Query user name via id in B_server.\n";
		}
	};

	// Operation(Department) Interface
	class ServerDepartment {
	public:
		virtual void Insert(Department *department) = 0;
		virtual void QueryDepartment(int id) = 0;
	};
	// Concrete Operation(Department)
	class A_ServerDepartment : public ServerDepartment {
	public:
		void Insert(Department *department) {
			std::cout << "Add department into A_Server.\n";
		}
		void QueryDepartment(int id) {
			std::cout << "Query department name via id in A_server.\n";
		}
	};
	class B_ServerDepartment : public ServerDepartment {
	public:
		void Insert(Department *department) {
			std::cout << "Add department into B_Server.\n";
		}
		void QueryDepartment(int id) {
			std::cout << "Query department name via id in B_server.\n";
		}
	};

	// Use Simple Factory inside
	class DataAccess {
	private:
		// 0: A_Server
		// 1: B_Server
		static const int serverType = 1;
	public:
		ServerUser* CreateServerUser() {
			ServerUser *su = nullptr;
			switch (serverType) {
			case 0: default:
				su = new A_ServerUser;
				break;
			case 1:
				su = new B_ServerUser;
				break;
			}
			return su;
		}
		ServerDepartment* CreateServerDepartment() {
			ServerDepartment *sd = nullptr;
			switch (serverType) {
			case 0: default:
				sd = new A_ServerDepartment;
				break;
			case 1:
				sd = new B_ServerDepartment;
				break;
			}
			return sd;
		}
	};

	// Client end.
	void Execute() {

		// Assume there are two operations need to be added into server.
		User *user = new User;
		Department *department = new Department;

		DataAccess *da = new DataAccess;

		ServerUser *su = da->CreateServerUser();
		su->Insert(user);
		su->QueryUser(0);

		ServerDepartment *sd = da->CreateServerDepartment();
		sd->Insert(department);
		sd->QueryDepartment(0);

		delete user, department, da, su, sd;
	}
};

int main() {
	Example *example = new Example_4_Simple_Factory;
	example->Execute();
	delete example;
	return 0;
}