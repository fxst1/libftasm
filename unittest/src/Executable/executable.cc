#include "unittest.h"
Executable::Executable(size_t shared_size):
	proc(nullptr),
	shared(nullptr)
{
	this->proc = (struct s_process*)mmap(NULL, sizeof(struct s_process)
					, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON
					, -1, 0);
	bzero(this->proc, sizeof(struct s_process));
	this->proc->shared_size = shared_size;
	this->proc->shared = (uint8_t*)mmap(NULL, shared_size
							, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON
							, -1, 0);
	this->shared = this->proc->shared;
}
Executable::Executable(const Executable &e):
	proc(e.proc),
	shared(e.shared)
{ (void)e; }
Executable::~Executable(void)
{
	if (this->proc != nullptr)
	{
		if (this->proc->pid > 0)
		{
			if (this->proc->shared != nullptr)
				munmap(this->proc->shared, this->proc->shared_size);
			munmap(this->proc, sizeof(struct s_process));
		}
	}
}


std::string			Executable::signame(int signum)
{
	return (std::to_string(signum));
/*	if (signum == SIGINT)
		return ("SIGINT");
	else if (signum == SIGQUIT)
		return ("SIGQUIT");*/
	(void)signum;
}

void				Executable::launchprocess(Generator *g)
{
	pid_t			w;

	this->proc->ret = false;
	this->proc->pid = fork();
	if (this->proc->pid < 0)
	{
		this->proc->ret = false;
		std::cerr << "\x1b[31m" << "fork failed" << "\x1b[0m" << std::endl;
		exit(EXIT_FAILURE);
	}
	else if (this->proc->pid == 0)
	{
		this->proc->ret = this->exec(g);
		exit(EXIT_SUCCESS);
	}
	else
	{
		w = waitpid(this->proc->pid, &this->proc->status, 0);
		if (w < 0)
		{
			std::cerr << "\x1b[31m" << "waitpid failed" << "\x1b[0m" << std::endl;
			exit(EXIT_FAILURE);
		}

		if (WIFEXITED(this->proc->status))
			std::cout << "\x1b[36m" << "exited : " << std::to_string(WEXITSTATUS(this->proc->status)) << "\x1b[0m" << std::endl;
		else if (WIFSIGNALED(this->proc->status))
			std::cout << "\x1b[31m" << "killed : " << this->signame(WTERMSIG(this->proc->status)) << "\x1b[0m" << std::endl;
		else if (WIFSIGNALED(this->proc->status))
			std::cout << "\x1b[31m" << "stoped : " << this->signame(WSTOPSIG(this->proc->status)) << "\x1b[0m" << std::endl;

	}
}

void	Executable::trace(void)
{}

bool	Executable::exec(Generator *g)
{
	std::cout << "Default Exec" << std::endl;
	return (false);
	(void)g;
}

Executable	&Executable::operator=(const Executable &rhs)
{
	if (this != &rhs)
	{
		if (this->proc != nullptr)
		{
			if (this->proc->shared != nullptr)
				munmap(this->proc->shared, this->proc->shared_size);
			munmap(this->proc, sizeof(struct s_process));
		}
		this->proc = rhs.proc;
		this->shared = rhs.shared;
	}
	return (*this);
	(void)rhs;
}
