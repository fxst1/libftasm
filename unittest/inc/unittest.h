#ifndef UNITTEST_H
# define UNITTEST_H
# include <string>
# include <map>
# include <list>
# include <stack>
# include <iostream>
# include <dlfcn.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <sys/wait.h>
# include <sys/mman.h>

class		nulstring
{
	public:

		std::string		s;

		nulstring(const std::string &src = "(null)"):
			s(src)
		{}
		nulstring(const char *s):
			s(s ? s : "(null)")
		{}

		size_t			length(void)
		{
			if (this->s == "(null)")
				return (0);
			return (this->s.length());
		}

		const char		*c_str(void)
		{
			if (this->s == "(null)")
				return (nullptr);
			return (this->s.c_str());
		}
};

class		Generator
{
	public:

		Generator(void);
		Generator(const Generator &src);
		virtual ~Generator(void);

		const Generator&	operator=(const Generator &rhs);
		virtual std::string	gen(void);
};

class		EmptyGenerator: public Generator
{
	public:

		std::string			gen(void)
		{ return (""); }
};

class		NulGenerator: public Generator
{
	public:

		std::string			gen(void)
		{ return ("(null)"); }
};

extern "C" {

	struct s_process
	{
		int		pid;
		bool	ret;
		int		status;
		uint8_t	*shared;
		size_t	shared_size;
	};

}

class		Executable
{
	protected:

		struct s_process		*proc;
		uint8_t					*shared;

	public:

		Executable(size_t shared_size);
		Executable(const Executable &e);
		virtual ~Executable(void);

		static std::string	signame(int signum);


		void				launchprocess(Generator *g);
		virtual void		trace(void);
		virtual bool		exec(Generator *g = nullptr);
		virtual Executable	&operator=(const Executable &rhs);
};

class		RandomStringGenerator: public Generator
{
	private:

		size_t		len;

	public:

		RandomStringGenerator(size_t len = 0):
			Generator(),
			len(len)
		{}
		RandomStringGenerator(const RandomStringGenerator& src):
			Generator(src),
			len(src.len)
		{}
		~RandomStringGenerator(void)
		{}

		const RandomStringGenerator&	operator=(const RandomStringGenerator& rhs)
		{ (void)rhs; return (*this); }

		std::string			gen(void)
		{
			std::string		s = "";
			size_t			len = this->len == 0 ? rand() % 2048 : this->len;

			for (size_t i = 0; i < len; i++)
				s += std::to_string(rand() % 256);

			return (s);
		}
};

class		Unittest
{
	public:

		class	StackOfTest: public Executable
		{

			private:

				std::string				name;
				std::stack<Generator*>	tests;

			public:

				StackOfTest(const std::string &s = "stk_test", size_t shared_size = 0);
				StackOfTest(const StackOfTest &src);
				virtual ~StackOfTest(void);
				const StackOfTest		&operator=(const StackOfTest &rhs);
				virtual bool			start(void);
				void					push(Generator *g);
				void					push(Generator &g);
		};

		template<typename F>
		class		StackOfFuncTest: public StackOfTest
		{
			protected:

				void							*handle;
				F								sys_fptr;
				F								user_fptr;
				std::string						func;

			public:

				StackOfFuncTest(const std::string &funcname = "puts", size_t shared_size = 0):
					StackOfTest(funcname, shared_size),
					handle(dlopen(nullptr, RTLD_LOCAL | RTLD_LAZY)),
					sys_fptr(nullptr),
					user_fptr(nullptr),
					func(funcname)
				{
					std::string		s = "ft_" + funcname;

					std::cout << "Loading sys: " << funcname << ", user:" << s << std::endl;
					this->sys_fptr = (F)dlsym(this->handle, funcname.c_str());
					this->user_fptr = (F)dlsym(this->handle, s.c_str());
				}
				StackOfFuncTest(const std::string &user, const std::string &sys, size_t shared_size = 0):
					StackOfTest(sys, shared_size),
					handle(dlopen(nullptr, RTLD_LOCAL | RTLD_LAZY)),
					sys_fptr(nullptr),
					user_fptr(nullptr),
					func(sys)
				{
					this->sys_fptr = (F)dlsym(this->handle, sys.c_str());
					this->user_fptr = (F)dlsym(this->handle, user.c_str());
				}
				virtual ~StackOfFuncTest(void)
				{}
		};

		Unittest(void);
		~Unittest(void);
		void		appendTest(const std::string &func, StackOfTest *ex);
		void		launchprocess(const std::string &name, StackOfTest *ex, Generator *g = nullptr);
		void		start(void);

	private:

		std::map<std::string, StackOfTest*>	tests;
};

#endif
