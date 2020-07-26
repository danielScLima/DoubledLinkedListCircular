// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "doubledlinkedlistcircular.h"

TEST_CASE( "Testing leak ocurrence", "[single-file]" )
{
	DoubledLinkedListCircular l;

	l.insertAfterStart("a");
	l.insertAfterStart("b");
	l.insertAfterStart("c");
}

TEST_CASE( "Testing the insert and remove in the head", "[single-file]" )
{
	DoubledLinkedListCircular l;
	DoubledLinkedCircularNode* node = nullptr;

	l.insertAfterStart("a");
	l.insertAfterStart("b");
	l.insertAfterStart("c");

	node = l.removeAfterStart();
	REQUIRE (node->data.compare("c") == 0);
	delete node;

	node = l.removeAfterStart();
	REQUIRE (node->data.compare("b") == 0);
	delete node;
	
	node = l.removeAfterStart();
	REQUIRE (node->data.compare("a") == 0);
	delete node;
}

TEST_CASE( "Testing the insert in head and remove in the tail", "[single-file]" )
{
	DoubledLinkedListCircular l;
	DoubledLinkedCircularNode* node = nullptr;

	l.insertAfterStart("a");
	l.insertAfterStart("b");
	l.insertAfterStart("c");//a c b

	node = l.removeBeforeStart();
	REQUIRE (node->data.compare("b") == 0);
	delete node;

	node = l.removeBeforeStart();
	REQUIRE (node->data.compare("c") == 0);
	delete node;
	
	node = l.removeBeforeStart();
	REQUIRE (node->data.compare("a") == 0);
	delete node;
}

TEST_CASE( "Testing the insert in tail and remove in the head", "[single-file]" )
{
	DoubledLinkedListCircular l;
	DoubledLinkedCircularNode* node = nullptr;

	l.insertBeforeStart("a");//a
	l.insertBeforeStart("b");//a b
	l.insertBeforeStart("c");//a b c

	node = l.removeAfterStart();
	REQUIRE (node->data.compare("b") == 0);
	delete node;

	node = l.removeAfterStart();
	REQUIRE (node->data.compare("c") == 0);
	delete node;
	
	node = l.removeAfterStart();
	REQUIRE (node->data.compare("a") == 0);
	delete node;
}

TEST_CASE( "Testing the insert in tail and remove in the tail", "[single-file]" )
{
	DoubledLinkedListCircular l;
	DoubledLinkedCircularNode* node = nullptr;

	l.insertBeforeStart("a");
	l.insertBeforeStart("b");
	l.insertBeforeStart("c");

	node = l.removeBeforeStart();
	REQUIRE (node->data.compare("c") == 0);
	delete node;

	node = l.removeBeforeStart();
	REQUIRE (node->data.compare("b") == 0);
	delete node;
	
	node = l.removeBeforeStart();
	REQUIRE (node->data.compare("a") == 0);
	delete node;
}
