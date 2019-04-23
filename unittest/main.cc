#include "unittest.h"
extern "C"
{
	#include "libft.h"
}

typedef int		(*strcmp_call_t)(const char*, const char*);
typedef int		(*strncmp_call_t)(const char*, const char*, size_t);
typedef int		(*puts_call_t)(const char*);
typedef size_t	(*strlen_call_t)(const char*);
typedef t_list	*(*lstnew_call_t)(const void*, size_t);
typedef t_list	*(*lstnewnoa_call_t)(void*, size_t);

class		LibftasmUnittest: public Unittest
{
	protected:

		class	LstnewNoaTest: public Unittest::StackOfFuncTest<lstnewnoa_call_t>
		{
			private:

				struct lstshareddata
				{
					t_list					user;
					char					*sys_s;
					size_t					sys_len;
				};

				NulGenerator				nul;
				EmptyGenerator				empty;
				RandomStringGenerator		rand_any;
				RandomStringGenerator		rand_10;

			public :

				LstnewNoaTest(void):
					Unittest::StackOfFuncTest<lstnewnoa_call_t>("lstnew_noalloc", sizeof(struct lstshareddata)),
					nul(),
					empty(),
					rand_any(8),
					rand_10(10)
				{
					this->sys_fptr = nullptr;
					this->user_fptr = &ft_lstnew_noalloc;
					this->push(this->nul);
					this->push(this->empty);
					this->push(this->rand_10);
					this->push(this->rand_any);
				}
				LstnewNoaTest(const LstnewNoaTest &src):
					Unittest::StackOfFuncTest<lstnewnoa_call_t>(src),
					rand_any(src.rand_any),
					rand_10(src.rand_10)
				{}
				~LstnewNoaTest(void)
				{}

				const LstnewNoaTest		&operator=(const LstnewNoaTest &rhs)
				{
					if (this != &rhs)
					{
						Unittest::StackOfFuncTest<lstnewnoa_call_t>::operator=(rhs);
						this->rand_any = rhs.rand_any;
						this->rand_10 = rhs.rand_10;
					}
					return (*this);
				}

				bool		exec(Generator *g = nullptr)
				{
					struct lstshareddata	*data = (struct lstshareddata*)this->shared;
					nulstring			str(g->gen());
					t_list				*dupl;

					data->user.content = nullptr;
					data->user.content_size = 0;
					data->sys_s = (char*)str.c_str();
					data->sys_len = str.length();

					std::cout << "ft_lstnew_noalloc(" << str.s << ", " << std::to_string(data->sys_len) << ") = ";
					dupl = (*this->user_fptr)(data->sys_s, data->sys_len);
					if (dupl)
						data->user = *dupl;

					if (dupl == nullptr)
					{
						std::cout << "NULL is returned" << std::endl;
						return (true);
					}
					else if (dupl->content == data->sys_s &&
							dupl->content_size == data->sys_len)
					{
						std::cout << "referenced" << std::endl;
						return (true);
					}
					else
					{
						std::cout << "duplicated" << std::endl;
						if (dupl->content == nullptr)
						{
							std::cout << " lst.content is null" << std::endl;
							return (false);
						}
						return (strcmp((const char*)dupl->content, data->sys_s) == 0  &&
								dupl->content_size == data->sys_len);
					}
				}

				void		trace(void)
				{
					struct lstshareddata	*data = (struct lstshareddata*)this->shared;
					nulstring				tmp((const char*)data->user.content);

					std::cout << "User: {" << tmp.s << ", " << std::to_string(data->user.content_size) << "}" << std::endl;
					(void)data;
				}
		};

		class	LstnewTest: public Unittest::StackOfFuncTest<lstnew_call_t>
		{
			private:

				struct lstshareddata
				{
					t_list					user;
					const char				*sys_s;
					size_t					sys_len;
				};

				NulGenerator				nul;
				EmptyGenerator				empty;
				RandomStringGenerator		rand_any;
				RandomStringGenerator		rand_10;

			public :

				LstnewTest(void):
					Unittest::StackOfFuncTest<lstnew_call_t>("lstnew", sizeof(struct lstshareddata)),
					nul(),
					empty(),
					rand_any(8),
					rand_10(10)
				{
					this->sys_fptr = nullptr;
					this->user_fptr = &ft_lstnew;
					this->push(this->nul);
					this->push(this->empty);
					this->push(this->rand_10);
					this->push(this->rand_any);
				}
				LstnewTest(const LstnewTest &src):
					Unittest::StackOfFuncTest<lstnew_call_t>(src),
					rand_any(src.rand_any),
					rand_10(src.rand_10)
				{}
				~LstnewTest(void)
				{}

				const LstnewTest		&operator=(const LstnewTest &rhs)
				{
					if (this != &rhs)
					{
						Unittest::StackOfFuncTest<lstnew_call_t>::operator=(rhs);
						this->rand_any = rhs.rand_any;
						this->rand_10 = rhs.rand_10;
					}
					return (*this);
				}

				bool		exec(Generator *g = nullptr)
				{
					struct lstshareddata	*data = (struct lstshareddata*)this->shared;
					nulstring			str(g->gen());
					t_list				*dupl;

					data->user.content = nullptr;
					data->user.content_size = 0;
					data->sys_s = str.c_str();
					data->sys_len = str.length();

					std::cout << "ft_lstnew(" << str.s << ", " << std::to_string(data->sys_len) << ") = ";
					dupl = (*this->user_fptr)(data->sys_s, data->sys_len);
					if (dupl)
						data->user = *dupl;

					if (dupl == nullptr)
					{
						std::cout << "NULL is returned" << std::endl;
						return (true);
					}
					else if (dupl->content == data->sys_s &&
							dupl->content_size == data->sys_len)
					{
						std::cout << "referenced" << std::endl;
						return (true);
					}
					else
					{
						std::cout << "duplicated" << std::endl;
						if (dupl->content == nullptr)
						{
							std::cout << " lst.content is null" << std::endl;
							return (false);
						}
						return (strcmp((const char*)dupl->content, data->sys_s) == 0  &&
								dupl->content_size == data->sys_len);
					}
				}

				void		trace(void)
				{
					struct lstshareddata	*data = (struct lstshareddata*)this->shared;
					nulstring				tmp((const char*)data->user.content);

					std::cout << "User: {" << tmp.s << ", " << std::to_string(data->user.content_size) << "}" << std::endl;
					(void)data;
				}
		};

		class	StrlenTest: public Unittest::StackOfFuncTest<strlen_call_t>
		{
			private:

				struct shareddata
				{
					size_t					user;
					size_t					sys;
				};

				NulGenerator				nul;
				EmptyGenerator				empty;
				RandomStringGenerator		rand_10;

			public :

				StrlenTest(void):
					Unittest::StackOfFuncTest<strlen_call_t>("strlen", sizeof(struct shareddata)),
					nul(),
					empty(),
					rand_10(10)
				{
					this->sys_fptr = &strlen;
					this->user_fptr = &ft_strlen;
					this->push(this->rand_10);
					this->push(this->empty);
					this->push(this->nul);
				}
				StrlenTest(const StrlenTest &src):
					Unittest::StackOfFuncTest<strlen_call_t>(src),
					nul(),
					empty(),
					rand_10(10)
				{}
				~StrlenTest(void)
				{}

				const StrlenTest		&operator=(const StrlenTest &rhs)
				{
					if (this != &rhs)
					{
						Unittest::StackOfFuncTest<strlen_call_t>::operator=(rhs);
						this->rand_10 = rhs.rand_10;
						this->empty = rhs.empty;
						this->nul = rhs.nul;
					}
					return (*this);
				}

				bool		exec(Generator *g = nullptr)
				{
					struct shareddata	*data = (struct shareddata*)this->shared;
					nulstring			str(g->gen());

					std::cout << "strlen(" << str.s << ")" << std::endl;
					data->user = (*this->user_fptr)(str.c_str());
					data->sys = (*this->sys_fptr)(str.c_str());
					return (data->user == data->sys);
				}

				void		trace(void)
				{
					struct shareddata	*data = (struct shareddata*)this->shared;
					std::cout << "Sys: " << std::to_string(data->sys) << std::endl;
					std::cout << "User: " << std::to_string(data->user) << std::endl;
				}
		};

	private:

		StrlenTest		strlen_test;
		LstnewTest		lstnew_test;
		LstnewNoaTest	lstnewnoa_test;

	public:

		LibftasmUnittest(void):
			Unittest(),
			strlen_test(),
			lstnew_test()
		{
			this->appendTest("strlen", &this->strlen_test);
			this->appendTest("lstnew", &this->lstnew_test);
			this->appendTest("lstnew_noalloc", &this->lstnewnoa_test);
		}

		~LibftasmUnittest(void)
		{}
};

int			main(int ac, char **av)
{
	LibftasmUnittest			process;

	srand(time(NULL));
	process.start();
	return (0);
	(void)ac;
	(void)av;
}
