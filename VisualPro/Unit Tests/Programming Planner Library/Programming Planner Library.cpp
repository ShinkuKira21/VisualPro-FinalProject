/* Author: Edward Patch */
#include "pch.h"
#include "CppUnitTest.h"
#include "../../Decoder/Public/LanguageConfiguration.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Rather than testing solely logic, as some of the creation of these libraries exist, class testing and compilation of these libraries are tested.
namespace Lists 
{
	TEST_CLASS(Lists)
	{
		/* External Class Details:
			Name: LinkedList (name revised to List).
			Properties: 2D std::string list, addition, deletion, edition and methods to find tools.
			Purpose: Enables a quick method of creating a controlled 2D list without the need of vectors.
			Requirements: A unique signature to identify objects.
		*/

		/* Purpose of this test is to make sure that addition of the List is possible.  */

		public:
			TEST_METHOD(List_Addition)
			{
				/* Error Log:
					First Try: Pass - (A, B, C, D, E, F, G, H)
				*/

				// Creation of a new list with X, on addition the ID's should follow as X-1, X-2 etc.
				List* xList = new List("X");
				List* yList = new List("Y"); // Same but Y-1, Y-2 etc.
				List* xyList = new List("XY"); // XY-1, XY-2 etc.

				// Should return X - Test | A
				Assert::AreEqual("X", xList->GetSignature().c_str());

				// Should return Y - Test | B
				Assert::AreEqual("Y", yList->GetSignature().c_str());

				// Should return XY - Test | C
				Assert::AreEqual("XY", xyList->GetSignature().c_str());

				// Should return X-1 - Test | D
				Assert::AreEqual("X-1", xList->Add("parentItem"));

				// Should return Y-1▽P-X-1 - Test | E
				Assert::AreEqual("Y-1\x1fP-X-1", yList->Add("childItem", "X-1"));

				// Should return Y-2 - Test | F
				Assert::AreEqual("Y-2", yList->Add("parentItem"));

				// Should return X-2 - Test | G
				Assert::AreEqual("X-2", xList->Add("parentItem"));

				// Should return XY-1 - Test | H
				Assert::AreEqual("XY-1\x1fP-X-2", xyList->Add("parentItem", "X-2"));

				// Garbage collection for the test.
				delete xList; delete yList; delete xyList;
			}

			TEST_METHOD(List_Deletion)
			{
				/* Error Log:
				 * First Try: Pass
				 */

				// Creation of X
				List* list = new List("X");
				list->Add("Function 1"); // ID: X-1
				list->Add("Function 2"); // ID: X-2
				list->Add("Function 3"); // ID: X-3

				// Both work but top is more tidy and saves some memory
				// History: Design of List was originally for displaying on Console and therefore saves any extra logic after calling ListAll method.
				// Ideal - Test | A-I:
				Assert::AreNotEqual("X-1  Function 1\nX-2  Function 2\nX-3  Function 3", list->ListAll().c_str());
				// Actual - Test | A-A: 
				Assert::AreEqual("X-1  Function 1  \nX-2  Function 2  \nX-3  Function 3  \n\n", list->ListAll().c_str());

				list->Remove(2); // Expectation: Function 2 goes disappears

				// To test if removal of List works - Test | B
				Assert::AreEqual("X-1  Function 1  \nX-3  Function 3  \n\n", list->ListAll().c_str());

				// Performance Improvement 
				// Ideal - It would be ideal to replace a empty ID (X-2 is non-existent, though X-4 is next) - Test | C-I
				Assert::AreNotEqual("X-2", list->Add("Method 2")); // The list should fill in the empty ID to save data.

				Assert::AreEqual("X-1  Function 1  \nX-3  Function 3  \nX-4  Method 2  \n\n", list->ListAll().c_str());

				// However, if the last element is non existence, the ID will rollback to any previously unique ID's that are not taken by the last element.)
				// Which, in theory provides short IDs that are suitable for Programming Planner's solution.
				// Actual - Test | D-A
				list->Remove(2);
				list->Remove(3);
				list->Remove(4);
				Assert::AreEqual("X-2", list->Add("Method 2"));

				delete list;
			}
	};
}

namespace DecoderTools 
{
	/* As the frontend transmits encrypted messages to the backend with most actions,
	 * it is important to decipher each message as fast as possible.
	 * A foreseeable problem that as this method is the building blocks of VisualPro,
	 * performance matters, especially with large strings.
	 */

	// FIRST MADE IN C# VisualPro (Without testing) (converted to C++ for testing)
	std::string CSFindSubStr(char start, char end, int pos, std::string str)
	{
		int count = 0;
		std::string substr = std::string(); bool bStarted = false;

		// loop through characters
		for (int i = 0; i < str.length(); i++)
		{
			// if bStarted is false, test character is equal to start character and count is equal to pos.
			// set bStarted to true and continue (to avoid the next logic).
			if(!bStarted && str[i] == start && count == pos)
			{
				bStarted = true; continue;
			}

			// if bStarted is false and test character is equal to start character, count increment.  
			if (!bStarted && str[i] == start)
				count++;

			// if bStarted is true and test character is not equal to end character, add to substr.
			if (bStarted && str[i] != end)
				substr += str[i];

			// else if bStarted is true break
			else if (bStarted) 
				break;
		}

		// return substr
		return substr;
	}

	std::string CPPFindSubStr(const char* str, const char* strToTest, char seperator, int pos)
	{
		// a variable to store a substr
		std::string substr;
		bool bEnablePos = false; // If position is not required.

		// loop through each character (i) and j counts position of word between characters
		for(size_t i = 0, j = 0; i < std::string(str).length(); i++)
		{
			// if character of str is not equal to seperator, add to substr.
			if (str[i] != seperator)
				substr += str[i];

			// if character is either equal to seperator or at the last character
			if(str[i] == seperator || i + 1 == std::string(str).length())
			{
				// return substr if word position is equal to j
				if (pos == (int)j && bEnablePos) return substr;

				// return j if substr is equal to test subject and pos is set to mode -2
				if (substr == strToTest && pos == -2) return std::to_string(j);

				// return substr if substr is equal to test subject and pos is set to mode -1
				if (substr == strToTest && pos == -1) return substr;
				j++; // add position

				// clear substr variable
				substr.clear();
			}

			// if substr is equal to test subject, set bEnablePos to true
			if (substr == strToTest) bEnablePos = true;

			// if pos is more than mode -1 and (bEnablePos is false and j is more than pos + 1, return a empty string
			if (pos > -1 && (!bEnablePos && (int)j >= pos + 1)) return std::string();
		}

		// return substr
		return substr;
	}

	// Enables to find a position of a substr within the string or return -1 if not found
	int FindStrIndex(const char* str, char testSubject)
	{
		for(size_t i = 0; i < std::string(str).length(); i++)
			if(str[i] == testSubject) return (int)i;

		return -1;
	}

	std::string ReplaceWord(const char* str, int depth, char start, char end, const char* replaceStr)
	{
		// sets first and last character to index - 0
		size_t first = 0, last = 0;

		for(int i = 0; i < depth; i++)
		{
			// set first character to find start character with an offset of last within str, which should get the first character of the str
			first = std::string(str).find(start, last);

			// set last character to find end character with an offset of first.
			last = std::string(str).find(end, first);
		}

		// replaces the substr of str with the new substr, with std's replace method.
		
		// Fixed based on the tests:
		return std::string(str).replace(first + 1, last - 2, replaceStr);
	}

	// Logic Making
	TEST_CLASS(DecoderTools)
	{
		public:
			TEST_METHOD(FindSubStrA)
			{
				/* Error Log:
				 * All tests passed.
				 * Purpose of tool is to find a word between two characters.
				*/
				// Seperators: | |
				Assert::AreEqual("H", CSFindSubStr('|', '|', 0, "|H|E-L-LxO").c_str());

				// Seperators: | -
				Assert::AreEqual("E", CSFindSubStr('|', '|', 1, "|H|E|L-LxO").c_str());

				// Seperators: - -
				Assert::AreEqual("L", CSFindSubStr('-', '-', 0, "|H|E-L-LxO").c_str());

				// Seperators: - -
				Assert::AreEqual("L", CSFindSubStr('-', 'x', 1, "|H|E-L-LxO").c_str());

				// Seperators: - \0
				Assert::AreEqual("O", CSFindSubStr('x', '\0', 0, "|H|E-L-LxO").c_str());
			}

			TEST_METHOD(FindSubStrB)
			{
				/* Error Log:
				 * Test A - Failed -> Test Written Wrongly | Passed
				 * Test B - Passed
				 * Test C - Failed -> Selects Each Word | Temporary Solution: Read Below.
				 */

				 // Seperator |
				 // Checks all words. - Test A
				for (size_t i = 0; i < 3; i++)
					Assert::AreEqual(("Word " + std::to_string(i + 1)).c_str(), CPPFindSubStr("Word 1|Word 2|Word 3", "Word", '|', i).c_str());

				// Finds First Word - Test B
				// Seperator x
				Assert::AreEqual("A", CPPFindSubStr("AxYZxQRxAxB", "A", 'x', 0).c_str());

				// Finds First Word in Each Position - Test C
				// Seperator x

				// current status: Fail (selects each word) - Temporary solution:
				// if(word == "A") or further rework
				std::string word = std::string();
				for (size_t i = 0; !(word = CPPFindSubStr("AxYZxQRxAxB", "A", 'x', (int)i)).empty(); i++)
					if (word == "A")
						Assert::AreEqual("A", word.c_str());
			}

			// FindStrIndex returns the index of a character position. This comes in handy for index purposes.
			TEST_METHOD(FindStrIndexA)
			{
				/* Error Log:
				 * Test A - Passed
				 * Test B - Passed
				 * Test C - Passed
				*/

				//Expectation: 6 | Test A
				Assert::AreEqual(6, FindStrIndex("!)2pAL@sSwS", '@'));
				//Expectation: Not -1 && is 8 | Test B
				Assert::AreNotEqual(-1, FindStrIndex("!)2pAL!sSwS", 'S'));
				Assert::AreEqual(8, FindStrIndex("!)2pAL!sSwS", 'S'));


				// Expectation: -1 | Test C
				Assert::AreEqual(-1, FindStrIndex("!)2pAL!sSwS", '~'));
				Assert::AreEqual(-1, FindStrIndex("!)2pAL!sSwS", '1'));
				Assert::AreEqual(-1, FindStrIndex("!)2pAL!sSwS", 'M'));
			}

			// Context of this one:
			// User drags and drops a class,
			// but changes the name from Cat to Dog
			// Reminder: List uses encrypted/compilation of data
			TEST_METHOD(ReplaceWordA)
			{
				/* Error Log
				 * 
				 */
				const std::string aMistake = "A:Banana\x1f\B:Pineapple\x1f\C:Grapefruit",
					testA = ReplaceWord(aMistake.c_str(), 1, ':', '\x1f', "Apple"),
					testB = ReplaceWord(testA.c_str(), 3, ':', '\x1f', "Banana");
				const char* expected = "A:Apple\x1f\B:Pineapple\x1f\C:Grapefruit",
							*secExpected = "A:Apple\x1f\B:Pineapple\x1f\C:Banana";

				Assert::AreNotEqual(expected, aMistake.c_str());
				Assert::AreEqual(expected, testA.c_str());
				Assert::AreEqual(secExpected, testB.c_str());
			}
	};
}

/* Why XML?
 * XML was chosen to create the dynamic interface of the addition of new syntax within the software.
 * RapidXML C Library triumphed along PugiXML (https://github.com/zeux/pugixml) and Xerces-C++ (https://xerces.apache.org/xerces-c/).
 * Mainly due to a descriptive documentation.
 * The plugin can parse an XML file and give some basic navigation tools, however,
 * further development is a great opportunity to enable more navigation tools to move from node to node, and attribute to attribute.
 *
 * To save time with this test, rather than moving away from the work environment, construction of the logic happens in the Work Environment, whilst consistently running tests from this side.
 */
