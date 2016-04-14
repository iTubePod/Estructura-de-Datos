#include <iostream>
#include "Queue.h"
#include "Client.h"

int main ()
{
	Queue<Client> clients;
	Node<Client> * current;
	clients.push(Client("Gil", "deposit", 12568977));
	clients.push(Client("Lalo", "withdraw", 54546848));
	clients.push(Client("Edgar", "deposit", 48712444));
	current=clients.top();

}