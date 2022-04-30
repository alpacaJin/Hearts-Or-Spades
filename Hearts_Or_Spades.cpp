// CPSC120_HeartsOrSpades.cpp : This program is a text-based terminal adventure game called Hearts or Spades.
// Sandra Nguyen
// 12112021

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "card_Deck.h"
using namespace std;

/* PROTOTYPES */
void pauseAndClear();
void invalidCheck();
int higher_or_lower(int choiceDifficulty);
void displayItems1(vector<string> player1_ItemsVector);
void displayItems2(vector<string> player2_ItemsVector);


int main() {
	// LOCAL VARIABLES
	string player1Role, player2Role,
		player1Nick, player2Nick,
		character1_Spade = "Character 1", character2_Hart = "Character 2",
		PLAYER1, PLAYER2;
	bool invalid = false;

	int userChoice_Int;
	char userChoice_Char;

	vector<string> player1_ItemsVector;
	vector<string> player2_ItemsVector;

	int choiceDifficulty, wins;
	int recall;
	int flag1, flag2 = 0;
	int menuChoice;

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

	/* TITLE SCREEN */
	// Print text
	cout << endl << setw(67) << "Welcome To\n" << setw(70) << "HEARTS or SPADES\n" << setw(75) << "Developed by Sandra Nguyen\n" << endl;
	/* ASCII art */
	cout << "                                                                _____\n";		// 35 spaces
	cout << "                                    _____                _____ |6    |\n";
	cout << "                                   |2    | _____        |5    || v v |\n";
	cout << "                                   |  v  ||3    | _____ | v v || v v | _____\n";
	cout << "                                   |     || v v ||4    ||  v  || v v ||7    |\n";
	cout << "                                   |  v  ||     || v v || v v ||____9|| v v | _____\n";
	cout << "                                   |____Z||  v  ||     ||____S|       |v v v||8    | _____\n";
	cout << "                                          |____E|| v v |              | v v ||v v v||9    |\n";
	cout << "                                                 |____h|              |____L|| v v ||v v v|\n";
	cout << "                                                             _____           |v v v||v v v|\n";
	cout << "                                                     _____  |K  WW|          |____8 |v v v| \n";
	cout << "                                             _____  |Q  ww| |   {)|                 |____6|\n";
	cout << "                                      _____ |J  ww| |   {(| |(v)%%| _____\n";
	cout << "                                     |10 v ||   {)| |(v)%%| | v%%%||A_ _ |\n";
	cout << "                                     |v v v||(v)% | | v%%%| |_%%%>||( v )|\n";
	cout << "                                     |v v v|| v % | |_%%%O|        | \\ / |\n";
	cout << "                                     |v v v||__%%[|                |  .  |\n";
	cout << "                                     |___0I|                       |____V|\n\n" << endl;

	// Continue command
	cout << "Press [enter] to start! ";
	pauseAndClear();

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

	/* INSTRUCTIONS */
	// Print text
	cout << setw(70) << "--INSTRUCTIONS--\n" << endl;
	cout << "This is a two-player, text-based, adventure RPG game. As you move through the story, respond to all prompts with your keyboard and mouse (please follow instructions and input the appropriate answer of your choice)! "
		<< "Most of the game will be spent in individual player decision phases where you have the ability to alter the story to your liking (cooperation with your partner is advised but feel free to act in your best interest--after all, it is an apocalypse). "
		<< "At select intervals, namely high-risk moments, you two will come together to play a game of Higher or Lower--a luck-based card game where you decide if the second card is higher or lower than the first card--to decide the outcome. "
		<< "Your objective is to survive the post-apocalyptic world with both players alive and thriving at the end, however, in the event of a character death, the game will still continue.\n\n"

		<< "Items acquired in-game will be recorded for each playerand can be used to boost your chances of success. You will also be able to save your progress at certain checkpointsand return to them when the game is over.\n\n"

		<< "Remember to maintain the integrity of the game; control of the mouseand keyboard should be givenand received interchangeably to guarantee a fair environment. Most importantly, don't forget to have fun!\n\n" << endl;

	// Continue command
	cout << "Press any key to continue.. ";
	pauseAndClear();

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

	/* NARRATIVE CONTEXT */
	// Print text
	cout << setw(70) << "--NARRATIVE--\n" << endl;
	cout << setw(70) << "The Cybergeddon\n" << endl
		<< "It is the year 2070.\n\n"

		<< "The world went to war five years ago over a globalized sabotage of all computerized networks from a malicious terrorist organization that calls itself The Sword. "
		<< "With the internet swarming with hacker intelligence that could detect, infiltrate, and terminate any piece of technology made after 1983, the world erupted into chaos. "
		<< "Communication became dangerous, the military obsolete, and the ability to produce food and trade money practically nonexistent. The disintegration of the seven world powers into economic collapse left its people in a fit of panic and fear.\n\n"

		<< "Two years later, the world began to suffer from widespread pandemics, nuclear warfare, and territorial division of land and sea; the death count raged in the billions.\n\n"

		<< "Today, The Sword is the most advanced society on Earth; an oasis in an otherwise backward, apocalyptic world. "
		<< "Survivors have learned how to become invisible to the ever-present watch of their nation's corrupted cameras and satellites, relying solely on old tech and agricultural methods. "
		<< "Resistance is fewand far between, but rumors of a stronger tech being developed in the land of Amacstan is a harbinger for hope. A revolution is brewing and you are at the center of the restlessness.\n\n" << endl;

	// Continue command
	cout << "Press any key to continue.. ";
	pauseAndClear();

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

	/* CHARACTER INTRODUCTION */
	// Print text
	cout << setw(70) << "--Choose a role-- \n" << endl;
	cout << "Character 1 is a former SWAT officer who served for three years in the US Army before the Cybergeddon retired them to a small town in the pacific northwest. "
		<< "It soon became a highly-disputed area due to its rich and vast backcountry that hid it from the heat of the city, and they bunkered down like many others to avoid the disease and bloodshed that transpired from a large-scale, unorganized migration. "
		<< "During six months of isolation, they survived off of nothing but canned food and rainwater. Having grown up as a technician and trained in combat, they disabled all of their household electronics and made short and calculated trips to locations around town to collect old radios, cameras, and landlines. "
		<< "Eventually, they saw the landscape evolve into developed territory with factions and gangs; upon their insistence to join, they refused to pledge allegiance for fear of being bound to violence. And violence there was, as each group fought to control the flow of resources and safeguard their livelihoods. "
		<< "In a few years' time, the Amac Peace Accords were signed and there emerged Amacstan, one of the largest plots of civilization to thrive after The Sword's widescale cyber attack, located in mountainous, wooded country surrounded by miles of deserted city. "
		<< "Signified as an early resident, they now work for The Amac Council as a border patrol captain on the SE Station, establishing order and monitoring the flow of traffic 24/7.\n\n"

		<< "Attributes: Athletic, clever, loyal, humorous, impulsive, pessimistic.\n\n" << endl

		<< "Character 2 is a former computer engineer for NASA who fled with their family to a safe house in the country in the initial two weeks of the attack. "
		<< "Unfortunately, due to the scope of their profession and connection, they were targeted by enemy AI and separated from their loved ones. "
		<< "For years, they were forced to traverse the madness and degeneration of humankind as a whole, hopping from one refugee camp to another, suffering pain and starvation with the rest, but all the while learning the truth behind The Sword's methods and searching for their lost family. "
		<< "They were noticed and recruited by an underground operation located in Amacstan called PEN where they got back in touch with an old colleague from NASA. They began working as a messenger and eventually, an intelligence agent for PEN whose mission is to build top-tier technology that could counteract The Sword's cyber malware. "
		<< "As an outsider, they distrust the authoritarian, vulnerable state of Amacstan, but when called forth to help bring the technology into its final stages, they have no choice but to travel to the capital.\n\n"

		<< "Attributes: Good-natured, intelligent, practical, strict, impatient, unhealthy.\n\n" << endl;

	// Do-while loop to check invalid
	do {
		// Take user input - choose role & nickname
		cout << "Player 1, choose your role (Character 1, Character 2): ";
		getline(cin, player1Role);
		cout << "Player 2, choose your role (Character 1, Character 2): ";
		getline(cin, player2Role);
		cout << endl;
		cout << "Player 1, choose a nickname: ";
		getline(cin, player1Nick);
		cout << "Player 2, choose a nickname: ";
		getline(cin, player2Nick);

		// Continue command
		cout << endl << "\nLOADING... \a";	// Beep
		pauseAndClear();

		/* Display credentials */
		invalid = false;
		// Character 1
		if (player1Role == character1_Spade) {
			PLAYER1 = player1Nick;
			cout << "Welcome.. " << player1Nick << " Spade, 0392 of Amacstan!\n" << endl;
		}
		else if (player2Role == character1_Spade) {
			PLAYER1 = player2Nick;
			cout << "Welcome.. " << player2Nick << " Spade, 0392 of Amacstan!\n" << endl;
		}
		// Character 2
		if (player1Role == character2_Hart) {
			PLAYER2 = player1Nick;
			cout << "Welcome.. " << player1Nick << " Hart, 7385 of Amacstan!\n" << endl;
			break;
		}
		else if (player2Role == character2_Hart) {
			PLAYER2 = player2Nick;
			cout << "Welcome.. " << player2Nick << " Hart, 7385 of Amacstan!\n" << endl;
			break;
		}
		// Invalid check - spelling
		if (player1Role != character1_Spade || player1Role != character2_Hart || player2Role != character1_Spade || player2Role != character2_Hart) {
			invalidCheck();
		}
		// Invalid check - matching
		else if (player1Role == player2Role) {
			invalidCheck();
		}
	} while (invalid = true);

	// ASCII art
	cout << endl;
	cout << "                              .------.\n";
	cout << "           .------.           |A .   |\n";
	cout << "           |A_  _ |    .------; / \\  |\n";
	cout << "           |( \\/ )|-----. _   |(_,_) |\n";
	cout << "           | \\  / | /\\  |( )  |  I  A|\n";
	cout << "           |  \\/ A|/  \\ |_x_) |------'\n";
	cout << "           `-----+'\\  / | Y  A|\n";
	cout << "                 |  \\/ A|-----'\n";
	cout << "                 `------'\n" << endl;

	// Continue command
	cout << endl << "Press any key to continue.. ";
	pauseAndClear();

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

	/* SCENE 1: CHARACTER 1 */
	// Print text
	cout << setw(55) << "--" << PLAYER1 << "'s POV--\n" << endl;
	cout << "It is a cloudy, moist January morning in the foothills of Amacstan. The sun has just risen, casting beams of soft, golden light onto the faces of your men as they look out towards the eastern border. "
		<< "A horse-drawn caravan, a rarity to see nowadays, is currently holding up the checkpoint gateway. You can see a family of three--mother, toddler, older brother--disputing with the officers on the ground. The unit has searched the wagon as of common practice and seems hesitant in allowing passage to the travelers.\n\n"

		<< "Press [s] to speak ";	// Break text into sections
	pauseAndClear();

	cout << "\"Lieutenant,\" you say to the dark-haired woman beside you, \"give me a report on the situation.\"\n\n"
		<< "She nods and speaks something unintelligible into her walkie-talkie. You see an officer below pick up the transmission and signal to their comrades to hold. The harnessed horse nickers, pawing the ground impatiently as the sunrise warms the earth and dispels the dew gathered from last night's rain. "
		<< "You know there are at least a couple more refugees waiting on the other side of the city's walls hoping to seek aid, and perhaps a supply truck carrying medicine or fuel; there is always constant activity needing to be monitored.\n\n"

		<< "\"It looks like BLUE found a strange, sorta, unidentifiable device on the female,\" Navarette 0470-A, your second in command, says with furrowed brows, \"It's for the baby... this \"asthma inhaler\" but the manufacture date and properties are unknown. She won't give it up for inspection, captain.\"\n\n"

		<< "Asthma inhaler, huh. You run a hand down your face, rubbing the drowsiness out of your eyes, then check your posture. It's been a long time since you've seen one in use. They used to come smart, didn't they, with some sort of digital scanning feature, six or seven years ago? These outsiders seem unusually well-off, now that you think about it. "
		<< "They can afford to nurture an apocalypse baby--with no hospitals, you can only imagine it to be an arduous task--, and own a caravan on top of that?\n\n"

		<< "It might just be your skeptical side talking, but you remind yourself of your responsibility to deal with potential security risks objectively.\n\n"

		<< "\"Mm, we've got more information Spade 0392-A,\" Navarette continues, \"the male, 22, claims he was a licensed nurse at Southshore Medical Clinic, a good 200 miles from here near what used to be Santa Cruz. They've been traveling for weeks; they're short on supplies...and desperate.\"\n\n"

		<< "Press [s] to speak ";
	pauseAndClear();

	cout << "\"Everyone's desperate these days,\" you say with a halfhearted chuckle. You hang your arms over the side of the banister and stare down intently at the travelers. It'd be cruel to deny refuge to these outsiders. They look able-bodied, their horse can be put to good use plowing the fields, and as for the inhaler, well, The Sword would've taken care of it a long time ago.\n\n"

		<< "There is only one wise choice here.\n\n" << endl

		<< "What is your decree?\n\n"

		<< "1. It is too dangerous. With no access to background checks, you can only rely on their word, and your gut feeling says they are lying. The country is full of spies and traitors; as captain, you cannot allow room for loose ends in Amacstan.\n\n"
		<< "2. They are not a threat. Your moral compass says to help them. It's brutal out there, and Amacstan is a beacon of safety and rebuilding. Besides, all new residents will be monitored closely for the next two weeks.\n" << endl;

	// Do-while loop to check invalid
	do {
		cout << "Enter your choice (1, 2): ";
		cin >> userChoice_Int;

		// Switch case for two choices
		invalid = false;
		switch (userChoice_Int) {
		case 1:
			recall = 1;
			cout << endl << "\nLOADING... \a";
			pauseAndClear();

			// Print text
			cout << "\"Thank you, Lieutenant Navarette,\" you sigh deeply, \"but I'm afraid I will not grant their passage. Our protocol is strict; refusing to hand over a suspected possession is a violation of our laws. I will not jeopardize the integrity of our division so easily... Tell BLUE to send them away.\"\n\n"

				<< "Understandable, captain.\"\n\n"

				<< "You watch as the unit nods their approval and informs the travelers of your command, pistols hanging heavy at their belts and armbands bleeding velvet. The lady seems to break down a little; the toddler in her arms starts up a wail and their brother has his head down. They are young and will be accepted elsewhere; you try to convince yourself. "
				<< "The sun glares down on the backs of the retreating travelers as the next group takes their place. The winds pick up and you leave your spot by the balcony of the SE station watchtower. You have a feeling the devil will beat his wife today... it's not a good sign.\n" << endl;

			cout << "     --<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--\n\n" << endl;	// End of scene marker

			// Continue command
			cout << "Press any key to continue.. ";
			pauseAndClear();
			break;
		case 2:
			recall = 2;
			cout << endl << "\nLOADING... \a";
			pauseAndClear();

			// Print text
			cout << "\"I will put my faith into these folks,\" you murmur, \"thank you, Lieutenant Navarette. I will grant their passage; it is the right thing to do. We have a responsibility to ensure these people have a place to call home, and in showing kindness, we set a good example for the other divisions... Tell BLUE to send them through.\"\n\n"

				<< "Understood, captain.\"\n\n"

				<< "You watch as the unit nods their approval and informs the travelers of your command, armbands bleeding velvet. The lady brightens up with a smile and cries of joy that seems to put your men at ease. Any lingering doubts you have about the family disappear; they were scared is all. "
				<< "The sun glares down on the backs of the travelers as they make their way into the city and the next group takes their place. The winds pick up and you leave your spot by the balcony of the SE station watchtower. You have a feeling the devil will beat his wife today... it's not a good sign.\n" << endl;

			cout << "     --<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--\n\n" << endl;

			// Continue command
			cout << "Press any key to continue.. ";
			pauseAndClear();
			break;
		default:
			invalidCheck();
			break;
		}
		break;
	} while (invalid = true);

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

	/* SCENE 1: CHARACTER 2 */
	// Print text
	cout << setw(55) << "--" << PLAYER2 << "'s POV--\n" << endl;
	cout << "You open your eyes to the sound of indistinct talking and the clapping of metal pans against one another. It is unfamiliar to hear this much, carefree, noise and you startle up out of your bed, reaching instinctively for the knife hidden under your pillow. It hits you then, the pleasant sunlight through the window and the events of last night's trainwreck of an initiation. "
		<< "You trace a finger over the tattoo stamped permanently into your wrist, 7385-B, and growl in distaste. You are now just another number to the rascals who run this city... you are no longer free.\n\n"

		<< "You exit the cottage you are temporarily assigned to and pick your way through the busy streets. What used to be a deserted and dingy, rain-slicked square, has blossomed into a riveting marketplace full of people and goods. You pull your cloth mask up above your nose, but not before smelling a waft of sweet corn puff pasty and spice that makes your heart dance with joy. "
		<< "The silver and copper coins (half pension from the soldiers, half delivered by your friend) in your leather satchel jingle enthusiastically. You keep a tight grip on your bag as you weave around the children playing soccer in the dirt and glance down at your watch: 7:29 AM.\n\n"

		<< "If you hurry, you can grab a bite to eat and catch the train at eight o'clock. However, this is your first time in Amacstan and you don't know your way around. You brush through a flock of chickens pecking in the dirt, your cloak fanning out behind you. The number of stalls thins the further you walk; you need to make a decision now.\n\n" << endl;

	// Do-while loop to check invalid
	do {
		cout << "Do you stop for food (y/n)? ";
		cin >> userChoice_Char;

		if (userChoice_Char == 'y') {
			cout << endl << "\nLOADING... \a";
			pauseAndClear();

			// Print text
			cout << "Let's buy some damn food. The train can wait, your stomach can't. You stroll over to one of the tents where an old woman in a brown robe is standing with her seven/eight-year-old daughter shooing the flies.\n\n"

				<< "Press [s] to speak ";
			pauseAndClear();

			cout << "\"Hello,\" you say with a smile, mustering up the friendliness in your eyes, \"how much will these be?\" You point to a round hot cross bun with cinnamon glaze and sesame seeds.\n\n"

				<< "\"Two for three copper, dear.\"\n\n" << "It seems like a fair price.\n\n" << "\"Mm, I'll take two please--\"\n\n" << "\"Try this one! This one! Guava!\" the girl with matching golden locks squeals and points to a crispy croissant laid out beside the buns. You raise your brows and laugh softly at her charm.\n\n"

				<< "\"How adorable,\" you marvel and nod to the woman who begins to package the pastries.\n\n" << "\"I try to give her the best life I am capable of,\" she replies with affection and looks up to catch your eye, \"did you come here alone, dear?\"\n\n"

				<< "You accept the paper bag and ruffle in your coin purse. You're not used to having people ask.\n\n" << "\"Actually...\"\n\n" << endl;

			cout << "What do you do?\n\n"

				<< "1. Tell the truth. You have nothing to be afraid of.\n\n"
				<< "2. Lie. It is easier that way.\n" << endl;

			do {
				cout << "Enter your choice (1, 2): ";
				cin >> userChoice_Int;

				// Switch case for two choices
				invalid = false;
				switch (userChoice_Int) {
				case 1:
					cout << endl << "\nLOADING... \a";
					pauseAndClear();

					// Print text
					cout << "\"... I'm looking for my family,\", you say, surprised at your honesty, \"we were separated right at the beginning, five years ago.\" you furrow your brows in recollection of the drones... the guns... and their screams.\n\n"
						<< "\"I've never once stopped searching, but every refugee camp, every little town, every rescue team I've come across; no luck.\" You exhale slowly, warm breath fogging up the lenses of your glasses. \"I don't... at this point, I don't know if they’re still ali--\"\n\n"

						<< "You feel a strong gloved hand on your shoulder.\n\n" << "\"I'm sorry you had to go through that, dear. You are so brave.\" She gives a squeeze of reassurance and you suppress a shudder, not used to sharing such an intimate moment with a stranger. \"On the south side of town, there’s a resident registry building. Give that a look when you have the time.\"\n\n"

						<< "You nod sullenly.\n\n" << "\"You will find them eventually, I just know it. Things will get better. The young will live on to see this Earth heal.\"\n\n" << "Your breath hitches. That phrase... seems so familiar but you can't seem to place it.\n\n" << "\"Things. Will. Be. O-kay,\" the little girl babbles, staring up with you with large, green eyes.\n\n"
						<< "\"Yes, it will,\" you clear your throat. \"Thank you so much...\"\n\n" << "\"Rohesia West.\"\n\n" << "\"Thank you Rohesia for your kind words and the pastries. " << " It's " << PLAYER2 << " Hart, a pleasure to meet you,\" you respond with a smile, secretly grateful she chose to omit the orthodox Amacstan numbering.\n\n" << "\"The pleasure is all mine.\"\n" << endl;

					// Continue command
					cout << endl << "Press any key to continue.. ";
					pauseAndClear();

					// Add Item 
					cout << "ITEM ACQUIRED: Pastries\a\n\n" << endl;
					player2_ItemsVector.push_back("Pastries");

					// ASCII art
					cout << "        ____                                    ?~~bL\n";
					cout << "       z@~ b                                    |  `U,\n";
					cout << "      ]@[  |                                   ]'  z@'\n";
					cout << "      d@~' `|, .__     _----L___----, __, .  _t'   `@j\n";
					cout << "     `@L_,   \" - ~`- - \"~-a,           `C.  ~\"\"O_    ._`@\n";
					cout << "      q@~'   ]P       ]@[            `Y=,   `H+z_  `a@\n";
					cout << "      `@L  _z@        d@               Ya     `-@b,_a'\n";
					cout << "       `-@d@a'       )@[               `VL      `a@@'\n";
					cout << "         aa~'   ],  .a@'                qqL  ), ./~\n";
					cout << "         @@_  _z~  _d@[                 .V@  .L_d'\n";
					cout << "          \"~@@@'  ]@@@'        __      )@n@bza@-\"\n";
					cout << "            `-@zzz@@@L        )@@z     ]@@=%-\"\n";
					cout << "              \"~~@@@@@bz_    _a@@@@z___a@K\n";
					cout << "                  \"~- @@@@@@@@@@@@@@@@@@~\"\n";
					cout << "                     `~~~-@~~-@@~~~~~'\n" << endl;

					// Continue command
					cout << endl << "Press any key to continue.. ";
					pauseAndClear();
					break;
				case 2:
					cout << endl << "\nLOADING... \a";
					pauseAndClear();

					// Print text
					cout << "\"... I'm here with my brother,\" you say smoothly, directing the attention away from yourself, \"he used to be a lawyer so the town hall is where he'ss at looking for a job.\"\n\n" << "\"Ah, that's good. We can do with a little better jurisdiction.\"\n\n" << "\"What... do you mean by that?\"\n\n"

						<< "\"I've been here a long time,\" the woman sighs, \"and things are a lot better than what they used to be but the Council...\" she lowers her voice, \"can be unpredictable at times.\"\n\n" << "Your breath hitches. It looks like outsiders are not the only ones distrusting of the city's government. "
						<< "You are about to press for more information when you notice the woman has a certain look in her eye that makes you hesitate. The little girl ogles you and tugs on her grandmother's sleeves.\n\n" << "\"Thank you... for the pastries,\" you clear your throat. \"It was a pleasure to meet you.\"\n\n" << "She nods and you turn away, a sick feeling in your stomach.\n\n" << endl;

					// Continue command
					cout << "Press any key to continue.. ";
					pauseAndClear();

					// Add Item 
					cout << "ITEM ACQUIRED: Pastries\a\n\n" << endl;
					player2_ItemsVector.push_back("Pastries");

					// ASCII art
					cout << "        ____                                    ?~~bL\n";
					cout << "       z@~ b                                    |  `U,\n";
					cout << "      ]@[  |                                   ]'  z@'\n";
					cout << "      d@~' `|, .__     _----L___----, __, .  _t'   `@j\n";
					cout << "     `@L_,   \" - ~`- - \"~-a,           `C.  ~\"\"O_    ._`@\n";
					cout << "      q@~'   ]P       ]@[            `Y=,   `H+z_  `a@\n";
					cout << "      `@L  _z@        d@               Ya     `-@b,_a'\n";
					cout << "       `-@d@a'       )@[               `VL      `a@@'\n";
					cout << "         aa~'   ],  .a@'                qqL  ), ./~\n";
					cout << "         @@_  _z~  _d@[                 .V@  .L_d'\n";
					cout << "          \"~@@@'  ]@@@'        __      )@n@bza@-\"\n";
					cout << "            `-@zzz@@@L        )@@z     ]@@=%-\"\n";
					cout << "              \"~~@@@@@bz_    _a@@@@z___a@K\n";
					cout << "                  \"~- @@@@@@@@@@@@@@@@@@~\"\n";
					cout << "                     `~~~-@~~-@@~~~~~'\n" << endl;

					// Continue command
					cout << endl << "Press any key to continue.. ";
					pauseAndClear();
					break;
				default:
					invalidCheck();
					break;
				}
				break;
			} while (invalid = true);
			break;
		}
		else if (userChoice_Char == 'n') {
			cout << endl << "\nLOADING... \a";
			pauseAndClear();

			// Print text
			cout << "You can get some food later on the train. Making it to your meeting on time is all you have in mind right now.\n\n" << endl;

			// Continue command
			cout << "Press any key to continue.. ";
			pauseAndClear();
			break;
		}
		else {
			invalidCheck();
		}

	} while (invalid = true);

	// Continue text
	cout << "You have been walking for what seems like miles in the direction you believe is the eastern ward's locomotive. You refrain from asking for directions, knowing well the civilians on this side of town will look at you with revulsion, for being new, for having a high number. You couldn't care less about status.\n\n"

		<< "You arrive at a nice cobblestone archway that opens out into a large courtyard, noticing a sign that reads Eastern Amac Station. You peer above some heads and see the steam train itself, emitting plumes of smoke into the air signaling that it's ready to debark. "
		<< "You squeeze into the ticket line and not long after you are seated in the last passenger car, a little out of breath and attempting to ignore the press of 30 other bodies.\n\n"

		<< "You are on your way to meet Dr.Sinclair, a colleague and friend you haven't seen since before The Cybergeddon; a period of five years that cannot be described as anything other than hell. It's been a while since you've been carried by something that isn't your own two feet, since you've had time to rest and contemplate. "
		<< "You wonder how much she's changed... how much you have changed. It's difficult to picture her through words on a page.\n\n"

		<< "You pull out the most recent letter calling you to Amacstan. You've read it about a million times but her enthusiasm and anxiousness bleed through the page like no other.\n\n"

		<< "Press [r] to read ";
	pauseAndClear();

	cout << "------------------------------------------------------------------------------------------------------------------------\n"
		<< "January 04, 2070\n\n" << "My dear Hart,\n\n\n" << "I hope this finds you well. I am relieved to hear that you had no trouble meeting with the Ranger. It is always a pleasure to hear from you.\n\n"

		<< "I have astounding news to share. We've finally acquired enough milk for Penny's cake from the pasture last week. It was an arduous task, as you know, there are few cows in good health and even less willing farmers. They requested much in exchange but more importantly, we have their favor, which will aid greatly in our preparations.\n\n"

		<< "I am afraid to say, however, that our neighbors have been coming around uninvited to inquire about the noise more often. The walls are thin and we can only stall for so long. I fear too, that we must reschedule the birthday party to an earlier date. I don't think Penny will mind much either way; she's preoccupied with the cat going missing.\n\n"

		<< "Alas, I have sent out the invitations to our closest friends and family. This party will be a joyous occasion amidst these tough times and I would like nothing more than to celebrate it with you. My Pigeon will tell you more when you arrive in Amacstan.\n\n" << "I hope to meet you soon, love. May you have a safe journey.\n\n\n" << "Warmly,\n" "Clair" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";

	cout << "     --<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--\n" << endl;

	// Continue command
	cout << endl << "Press any key to continue.. ";
	pauseAndClear();

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

	/* SCENE 2: CHARACTER 1 */
	// Print text
	cout << setw(55) << "--" << PLAYER1 << "'s POV--\n" << endl;
	cout << "The afternoon slump is beginning to hit you as you lounge in your office with a cup of black coffee in your hand. A loose folder of paperwork sits obtrusively on your desk but you haven't opened it, your attention focused instead on a pair of goldfinch singing outside your window. "
		"Their incessant little chirps of joy fill you with nostalgia--for a time in your childhood where your worries revolved around nothing but school and summer flings.\n\n"

		<< "Emitting a sigh, you begin to thumb through the stack of paper which consists mostly of newly-admitted resident information, notices of suspicious activity in the Southeast Ward, and letters from adjacent stations. You skim through pages of faces and numbers that all meld together into one cohesive blur, stamping and signing and making notes to do this or that... when something catches your eye.\n\n"

		<< "It is a letter from the captain of the Eastern Station, Cross 0255-A.You've never met them in person but you dislike them a hell of a lot. This jerk is always intruding into your station's affairs, nitpicking your authority, and blaming crime on your station's \"lack\" of checkpoint security with no identifiable reason. Granted, you’ve fired back on multiple occasions but that's only justified.\n\n"

		<< "A quick scan and you conclude that it's full of nonsense. More talk about some nonexistent threat against The Council and jab at your apparent incompetence. For someone so full of themselves, they sure are cowardly.\n\n" << "You throw their letter in the bin and open your desk drawer. Rummaging around, you pull out a small hand-held radio tucked in the back corner of the box and straighten its antenna. "
		<< "You glance at the door. When there's no sign of interruption, you begin working with it carefully, spinning the dial this way and that to find a channel clear of static. This is a powerful little device from the 1970s you managed to scavenge; it can pick up signals from a mile away and you have it hidden here in the station--the closest point of access you have to beyond Amacstan's borders. You cannot get caught with it.\n\n"

		<< "Endless streams of static electricity buzz softly in your ear. Some days you are able to pick up a snippet of a voice but it's been a few minutes and you've gotten nothing.\n\n" << endl;

	do {
		invalid = false;
		flag1 = 0;	// to break out of all nested loops
		flag1 = flag2;
		if (flag1 == 1) break;

		// 1st path split
		cout << "Keep trying (y/n)? ";
		cin >> userChoice_Char;

		if (userChoice_Char == 'y') {
			cout << endl << "\nLOADING... \a";
			pauseAndClear();

			// Print text
			cout << "You stand up and move over to your window, making sure to keep out of sight of any onlookers. You swivel the dial a few more times, listening intently and wondering if you've missed something. You angle the antenna in a different direction and raise the radio above your head... Nothing.\n\n" << endl;

			do {
				invalid = false;
				flag1 = 0;
				flag1 = flag2;
				if (flag1 == 1) break;

				// 2nd path split
				cout << "Keep trying (y/n)? ";
				cin >> userChoice_Char;

				if (userChoice_Char == 'y') {
					cout << endl << "\nLOADING... \a";
					pauseAndClear();

					// Print text
					cout << "You begin to feel anxious but remembering the sound of the voice on the other side--how commanding, how important it sounded--fills you with determination. You turn the dial millimeters at a time, leaving no stone unturned... Still nothing.\n\n" << endl;

					do {
						invalid = false;
						flag1 = 0;
						flag1 = flag2;
						if (flag1 == 1) break;

						// 3rd path split
						cout << "Keep trying (y/n)? ";
						cin >> userChoice_Char;

						if (userChoice_Char == 'y') {
							flag2 = 1;
							cout << endl << "\nLOADING... \a";
							pauseAndClear();

							// Print text
							cout << "You move away from the window towards the other side of the room, facing the city; hoping, waiting. You feel like Winston with his diary of thoughtcrime. That didn't end well, now did it.\n\n"

								<< "You don't know what you're looking for at this point. It could've been a random transmission you stumbled upon last week, a conversation between two you had no reason to pry on; or a prank, someone messing with the authorities and their systems. You could've imagined the whole thing, even.\n\n"

								<< "You grip your radio in frustration and toss it into your open drawer. You can't be putting your job on the line like this.\n\n" << "--It lands with a thunk and springs to life. You scramble down on all fours, heart in your throat and holding on to the radio for dear life. A melody wafts into your ear, melancholic but comforting. It is unfamiliar and it dwindles out into silence.\n\n"

								<< "You hold your breath, crushed, but then you hear it: the voice. A woman's voice purrs in your ear as the song restarts.\n\n"

								<< "     I'm just a penny on the train track\n" << "     Waitin' for my judgement day\n" << "     Come on baby girl let me see those legs\n" << "     Before I get flattened away\n\n" << "     I wait\n" << "     Yeah, I wait\n" << "     For something good, for something great\n\n"
								<< "     Stoppin' in somebody's old home town\n" << "     Gotta get that midnight meal\n" << "     If you can't get behind your own life\n" << "     Get behind that driving wheel~\n\n"

								<< "There is a knock at the door and you startle. You turn the radio off and push it deep into the drawer.\n" << endl;
							break;
						}
						else if (userChoice_Char == 'n') {
							flag2 = 1;
							cout << endl << "\nLOADING... \a";
							pauseAndClear();

							// Print text
							cout << "Frustrated, you grip the radio and toss it into your open drawer.\n\n" << "--It lands with a thunk and springs to life. You scramble down on all fours, heart in your throat and holding on to the radio for dear life. A melody wafts into your ear, melancholic but comforting. It is unfamiliar and it dwindles out into silence.\n\n"

								<< "You hold your breath, crushed, but then you hear it: the voice. A woman's voice purrs in your ear as the song restarts.\n\n"

								<< "     I'm just a penny on the train track\n" << "     Waitin' for my judgement day\n" << "     Come on~\n\n" << "There is a knock at the door and you startle. You turn the radio off and push it deep into the drawer. You desperately wanted to hear more.\n" << endl;
							break;
						}
						else {
							invalidCheck();
						}
					} while (invalid = true);
				}
				else if (userChoice_Char == 'n') {
					flag2 = 1;
					cout << endl << "\nLOADING... \a";
					pauseAndClear();

					// Print text
					cout << "Bummed, you return to your desk and toss the radio into your open drawer; it lands with a thunk among the random junk. You close your eyes and try to recall what exactly you heard last week that piqued your curiosity like this. It was a voice no doubt, that was immensely jumbled and marred by static, but you could distinctly remember how commanding--how important it sounded. "
						<< "You remind yourself to try again later.\n\n" << "There is a knock at the door and you startle.\n" << endl;
					break;
				}
				else {
					invalidCheck();
				}
			} while (invalid = true);
		}
		else if (userChoice_Char == 'n') {
			flag2 = 1;
			cout << endl << "\nLOADING... \a";
			pauseAndClear();

			// Print text
			cout << "Bummed, you toss the radio into your open drawer and it lands with a thunk among the random junk. You close your eyes and try to recall what exactly you heard last week that piqued your curiosity like this. It was a voice no doubt, that was immensely jumbled and marred by static, but you could distinctly remember how commanding--how important it sounded. "
				<< "You remind yourself to try again later.\n\n" << "There is a knock at the door and you startle.\n" << endl;
			break;
		}
		else {
			invalidCheck();
		}
	} while (invalid = true);

	// Continue text
	cout << "Press [s] to speak ";
	pauseAndClear();

	cout << "\"Who is it?\" you ask, keeping your tone neutral and patting the creases out of your clothes.\n\n" << "\"It's me, Navarette.\"\n\n" << "\"Ah, come in come in.\"\n\n"

		<< "Your second-in-command enters your office and you notice immediately the grim expression on her face. She isn't exactly a happy-go-lucky type of person but it's been three years since you've known her and you can tell that something's wrong.\n\n"

		<< "\"You missing that dogshit sitcom again, Nav?\" you tease.\n\n" << "She doesn't laugh and you lick your lips, growing serious.\n\n" << "\"What's happened.\"\n\n"

		<< "\"This came for you,\" she produces a paper scroll tied with a velvet ribbon, the symbol of The Amac Council. You accept it, heart dropping.\n\n" << "\"You haven't read it now, have you?\"\n\n" << "\"No, captain.\"\n\n"

		<< "You know she's only being apathetic because she's worried. You pull on the ribbon and unfold the scroll, half expecting to see a notice of dismissal but instead, it is a letter summoning you to a \"confidential meeting\".\n" << endl

		<< "Press [s] to speak ";
	pauseAndClear();

	cout << "\"Oh, I'm in trouble now,\" you chuckle and brush a hand through your hair, to which the lieutenant frowns.\n\n" << "\"No no, the General wants to speak to me... to us, Captain Cross and Dias included, at 2:30 PM with some representatives of The Council. Oh wait...\" you stare hard at the paper, \"I wasn’t supposed to tell anyone.\"\n\n"

		<< "\"Spade...\"\n\n" << "\"No worries, this stays between us. You're the only one I trust,\" you crack a smile.\n\n" << "\"What does The Council want with us,\" she muses, \"with these three stations specifically?\"\n\n"

		<< "\"You know we get the rowdiest bunch of outsiders there is. You have one apocalypse and suddenly people forget how to act.\"\n\n" << "\"It's tough down there in the poorer wards, you know it. We are already exiling all the criminals.\"\n\n"

		<< "\"They're taking Amacstan for granted, that's what. We've no place for bandits, rioters, and murderers. Maybe it's good that The Council is stepping in because it seems like we can't filter shit right at the gates.\"\n" << endl;

	// Recall path 
	if (recall == 1) {
		// Print text
		cout << "You remember turning away the family of three this morning and thank your past self for making the right decision. You can't be soft in a time of turbulence.\n\n";
	}
	else if (recall == 2) {
		// Print text
		cout << "You remember admitting the family of three this morning and grit your teeth in regret. Why were you so soft in a time of turbulence?\n\n";
	}

	// Continue text
	cout << "\"You are not responsible for other peoples' actions, Spade.\" Navarette sighs, \"We've gotta encourage people to stand together and work towards a better tomorrow. The Council's methods... are too violent. Their numbering system has divided us.\"\n\n"

		<< "You still. Their matching velvet armbands lay limp on their sleeves, so docile compared to when they are brought to life by Amacstan's downslope winds on many a mission. It's dangerous for officers to slander The Council. Even though you are in your private office, a feeling of uneasiness slinks into your gut.\n" << endl

		<< "Press [s] to speak ";
	pauseAndClear();

	cout << "\"Nav... you can't be saying things like that.\"\n\n" << "\"You know I'm right. We were both here during the last pruning event. It was sick, what they--\"\n\n" << "\"We are not allowed to speak of that, lieutenant.\"\n\n" << "\"I'm frustrated--\"\n\n"

		<< "\"Lieutenant!\" you silence her, \"Keep your cool. You are out of line.\"\n\n" << "Navarette lowers her head and apologizes curtly.\n\n" << "\"I will leave you to prepare for your meeting, captain,\" she deadpans.\n\n"

		<< "You press a palm to your temple, hiding your irritation. You watch the back of her head as she turns and strides toward the door, but a pause, and you two lock eyes.\n\n" << "\"Please, be alert.\"\n\n"

		<< "You are once again alone. But your mouth is dry and you can't quell the bounce in your leg, so you push this conversation out of mind and pick up a knapsack, which in goes some personal documents and items. You hesitate before adding the mini radio too. Checking your belt for your pistol and blade last, you exit  your office with sullen footsteps.\n\n"

		<< "What you later come to realize is that from this point on, your life will never be the same.\n\n" << endl;

	cout << "     --<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--\n" << endl;

	// Continue command
	cout << endl << "Press any key to continue.. ";
	pauseAndClear();

	// Add Item 
	cout << "ITEM ACQUIRED: Mini Radio\a\n\n" << endl;
	player1_ItemsVector.push_back("Mini Radio");

	// ASCII art
	cout << "                       !\n";
	cout << "                       |\n";
	cout << "                       |    |~/\n";
	cout << "                       |   _|~\n";
	cout << "         .============.|  (_|   |~/\n";
	cout << "       .-;____________;|.      _|~\n";
	cout << "       | [_________I__] |     (_|\n";
	cout << "       |  \"\"\"\"\" (_)(_)  |\n";
	cout << "       | .=====..=====. |\n";
	cout << "       | |:::::||:::::| |\n";
	cout << "       | '=====''=====' |\n";
	cout << "       '----------------'\n" << endl;

	// Continue command
	cout << endl << "Press any key to continue.. ";
	pauseAndClear();

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

	/* SCENE 2: CHARACTER 2 */
	// Print text
	cout << setw(55) << "--" << PLAYER2 << "'s POV--\n" << endl;
	cout << "THIS SCENE IS IN THE WORKS. THANK YOU FOR YOUR PATIENCE.\n" << endl;

	// Continue command
	cout << endl << "Press any key to continue.. ";
	pauseAndClear();

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

	// Call player 1's item list
	displayItems1(player1_ItemsVector);

	// Continue command
	cout << endl << "Press any key to continue.. ";
	pauseAndClear();

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

	// Call player 2's item list
	displayItems2(player2_ItemsVector);

	// Continue command
	cout << endl << "Press any key to continue.. ";
	pauseAndClear();

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

	// Call Higher or Lower game
	choiceDifficulty = 3;
	wins = higher_or_lower(choiceDifficulty);

	if (wins >= (choiceDifficulty - 1)) {	// Majority
		cout << "Favorable outcome\n";
	}
	else if (wins < choiceDifficulty) {
		cout << "Unfavorable outcome\n";
	}
	else {
		invalidCheck();
	}

	// Continue command
	cout << endl << "Press any key to continue.. ";
	pauseAndClear();

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

	/* ENDING SCREEN */
	// Print text
	cout << endl << setw(68) << "This Was\n" << setw(72) << "HEARTS or SPADES\n" << setw(74) << "Thank You For Playing\n" << endl;
	/* ASCII art */
	cout << "                                                                _____\n";
	cout << "                                    _____                _____ |6    |\n";
	cout << "                                   |2    | _____        |5    || v v |\n";
	cout << "                                   |  v  ||3    | _____ | v v || v v | _____\n";
	cout << "                                   |     || v v ||4    ||  v  || v v ||7    |\n";
	cout << "                                   |  v  ||     || v v || v v ||____9|| v v | _____\n";
	cout << "                                   |____Z||  v  ||     ||____S|       |v v v||8    | _____\n";
	cout << "                                          |____E|| v v |              | v v ||v v v||9    |\n";
	cout << "                                                 |____h|              |____L|| v v ||v v v|\n";
	cout << "                                                             _____           |v v v||v v v|\n";
	cout << "                                                     _____  |K  WW|          |____8 |v v v| \n";
	cout << "                                             _____  |Q  ww| |   {)|                 |____6|\n";
	cout << "                                      _____ |J  ww| |   {(| |(v)%%| _____\n";
	cout << "                                     |10 v ||   {)| |(v)%%| | v%%%||A_ _ |\n";
	cout << "                                     |v v v||(v)% | | v%%%| |_%%%>||( v )|\n";
	cout << "                                     |v v v|| v % | |_%%%O|        | \\ / |\n";
	cout << "                                     |v v v||__%%[|                |  .  |\n";
	cout << "                                     |___0I|                       |____V|\n\n" << endl;

	cout << "Developer notes: I really appreciate you coming on this journey with me, I hope you enjoyed! I worked very hard to develop the story and make this experience as fun and interactive as possible, so thank you again for being one of my first real testers! Also, credit to asciiart.eu for all their beautiful designs. See you on the other side!\n\n";

	// Continue command
	cout << endl << "Press any key to continue.. ";
	pauseAndClear();

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

	/* MENU OPTIONS */
	// Print text
	cout << setw(75) << "--Menu Options--\n" << endl;
	cout << "Would you like to:\n\n"
		<< "1. Restart the game\n" << "2. Return to a checkpoint\n" << "3. Exit the game\n\n"
		<< "Enter your choice (1, 2, 3): ";

	do {
		cin >> menuChoice;

		if (menuChoice == 1) {
			exit(0);
		}
		else if (menuChoice == 2) {
			// Checkpoint code
		}
		else if (menuChoice == 3) {
			exit(0);
		}
		else {
			invalidCheck();
		}
	} while (invalid = true);

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

	system("pause>0");
	return 0;
}


/* FUNCTIONS */
// Continue Command Function
void pauseAndClear() {
	system("pause>0");
	system("CLS");		// Clear console
}

// Invalid Check Function
void invalidCheck() {
	cout << "Invalid input. Please check your spelling and try again.\n" << endl;
	bool invalid = true;
}

// HIGHER OR LOWER Function
int higher_or_lower(int choiceDifficulty = 0) {
	// Local variables
	// choiceDifficulty determines how many rounds are played
	char instructions,
		cardChoice;
	int dealerRank,
		playerRank,
		dealerSuit,
		playerSuit,
		wins = 0;
	bool invalid;
	card_Deck card;

	// Instructions
	cout << "Read instructions (y/n)? ";
	cin >> instructions;

	cout << endl << "\nLOADING... \a";
	pauseAndClear();

	do {
		if (instructions == 'y') {
			// Print text
			cout << setw(70) << "--Instructions--\n\n" << "A random card will be drawn from the deck. Note that there are 4 suits (clubs, diamonds, hearts, & spades) and 13 ranks (Ace, King, Queen, Jack, 10, 9, 8, 7, 6, 5, 4, 3, 2) for a total of 52 cards. Your goal is to guess correctly whether the next card will be higher or lower than the current card. "
				<< "Depending on how far you are along in the story and how polarizing the choices are, you may play many rounds. Your success or failure will determine how you advance.\n\n" << "Remember, this is a DUO round. Collaborate with your partner.\n\n";

			// Continue command
			cout << endl << "Press any key to continue.. ";
			pauseAndClear();
			break;
		}
		else if (instructions == 'n') {
			break;
		}
		else {
			invalidCheck();
		}
	} while (invalid = true);


	/* CARD GAME */
	cout << setw(72) << "--HIGHER or LOWER--\n\n" << setw(81) << "E N T E R I N G  D A N G E R  Z O N E\n\n" << setw(73) << "Proceed with caution\n\n" << endl;

	// ASCII art
	cout << "                                                       _______\n";
	cout << "                                                       |.-----.|\n";
	cout << "                                                       ||x . x||\n";
	cout << "                                                       ||_.-._||\n";
	cout << "                               O                       `--)-(--`                       O\n";
	cout << "                          {o)xxx|===============-     __[=== o]___     -===============|xxx(o}\n";
	cout << "                                O                     |:::::::::::|\\                   O\n";
	cout << "                                                      `-======== = -`()\n" << endl;

	// Continue command
	cout << endl << "Press any key to continue.. ";
	pauseAndClear();

	for (int i = 1; i <= choiceDifficulty; i++) {
		// Print round
		cout << "--ROUND " << i << "--" << endl << endl;

		// Dealer deck
		card = card_Deck();
		dealerRank = card.getRank();
		dealerSuit = card.getSuit();

		cout << "You draw a " << card.getRankString() << " of " << card.getSuitString() << ".\n\n";

		// Invalid check
		do {
			invalid = false;
			cout << "Will the next card be higher or lower (h/l)? ";
			cin >> cardChoice;

			cout << endl << "\nLOADING... \a";
			pauseAndClear();

			// Player deck
			card = card_Deck();
			playerRank = card.getRank();
			playerSuit = card.getSuit();

			cout << "You draw a " << card.getRankString() << " of " << card.getSuitString() << ".\n\n";

			// Check rank - lose
			if ((cardChoice == 'h' && (dealerRank > playerRank)) || (cardChoice == 'l' && (dealerRank < playerRank))) {
				// Check suit - lose
				if ((cardChoice == 'h' && ((dealerSuit >= playerSuit) || dealerSuit < playerSuit)) || ((cardChoice == 'l' && (dealerSuit <= playerSuit)) || (dealerSuit > playerSuit))) {
					cout << "What a shame. Better luck next time.\n\n";

					// Continue command
					cout << endl << "Press any key to continue.. ";
					pauseAndClear();
					break;
				}
				else {
					cout << "Your choice got lost in the wind. Excuse the dealer!\n\n";

					// Continue command
					cout << endl << "Press any key to continue.. ";
					pauseAndClear();
					break;
				}
			}
			// Check equal rank & diff suit - lose
			else if ((cardChoice == 'h' && ((dealerRank == playerRank) && (dealerSuit > playerSuit)) || (cardChoice == 'l' && ((dealerRank == playerRank) && (dealerSuit < playerSuit))))) {
				cout << "What a shame. Better luck next time.\n\n";

				// Continue command
				cout << endl << "Press any key to continue.. ";
				pauseAndClear();
				break;
			}
			// Check rank - win
			else if ((cardChoice == 'h' && (dealerRank < playerRank)) || (cardChoice == 'l' && (dealerRank > playerRank))) {
				// Check suit - win
				if ((cardChoice == 'h' && ((dealerSuit <= playerSuit) || (dealerSuit > playerSuit))) || (cardChoice == 'l' && ((dealerSuit >= playerSuit) || (dealerSuit < playerSuit)))) {
					cout << "Congrats! Luck is on your side.\n\n";
					wins++;

					// ASCII art
					cout << "                       ,\n";
					cout << "                      /|      __\n";
					cout << "*             +      / |   ,-~ /             +\n";
					cout << "     .              Y :|  //  /                .         *\n";
					cout << "         .          | jj /( .^     *\n";
					cout << "               *    >-\"~\"-v\"              . * .\n";
					cout << "*                  /       Y\n";
					cout << "   .     .        jo  o    |     .            +\n";
					cout << "                 ( ~T~     j                     +     .\n";
					cout << "      +           >._-' _./         +\n";
					cout << "               /| ;-\"~_  l\n";
					cout << "  .           / l/ ,-\"~\\ +\n";
					cout << "              \\//\\/      .- \\\n";
					cout << "       +       Y        /    Y\n";
					cout << "               l       I     !\n";
					cout << "               ]\\      _\\    /\"\\\n";
					cout << "              (\" ~----( ~   Y.  )\n";
					cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

					// Continue command
					cout << endl << "Press any key to continue.. ";
					pauseAndClear();
					break;
				}
				else {
					cout << "Your choice got lost in the wind. Excuse the dealer!\n\n";

					// Continue command
					cout << endl << "Press any key to continue.. ";
					pauseAndClear();
					break;
				}
			}
			// Check equal rank & diff suit - win
			else if ((cardChoice == 'h' && ((dealerRank == playerRank) && (dealerSuit < playerSuit)) || (cardChoice == 'l' && ((dealerRank == playerRank) && (dealerSuit > playerSuit))))) {
				cout << "Congrats! Luck is on your side.\n\n";
				wins++;

				// ASCII art
				cout << "                       ,\n";
				cout << "                      /|      __\n";
				cout << "*             +      / |   ,-~ /             +\n";
				cout << "     .              Y :|  //  /                .         *\n";
				cout << "         .          | jj /( .^     *\n";
				cout << "               *    >-\"~\"-v\"              . * .\n";
				cout << "*                  /       Y\n";
				cout << "   .     .        jo  o    |     .            +\n";
				cout << "                 ( ~T~     j                     +     .\n";
				cout << "      +           >._-' _./         +\n";
				cout << "               /| ;-\"~_  l\n";
				cout << "  .           / l/ ,-\"~\\ +\n";
				cout << "              \\//\\/      .- \\\n";
				cout << "       +       Y        /    Y\n";
				cout << "               l       I     !\n";
				cout << "               ]\\      _\\    /\"\\\n";
				cout << "              (\" ~----( ~   Y.  )\n";
				cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

				// Continue command
				cout << endl << "Press any key to continue.. ";
				pauseAndClear();
				break;
			}
			else {
				invalidCheck();
				pauseAndClear;
			}
		} while (invalid = true);
	}

	return wins;
}

// Items Functions
void displayItems1(vector<string> player1_ItemsVector) {
	cout << "--Items acquired--\n\n";

	// Display vector list
	for (int i = 0; i < player1_ItemsVector.size(); i++) {
		int num = 0;

		cout << num + 1 << ". ";
		cout << player1_ItemsVector[i] << endl;
	}
	cout << endl;
}
void displayItems2(vector<string> player2_ItemsVector) {
	cout << "--Items acquired--\n\n";

	// Display vector list
	for (int i = 0; i < player2_ItemsVector.size(); i++) {
		int num = 0;

		cout << num + 1 << ". ";
		cout << player2_ItemsVector[i] << endl;
	}
	cout << endl;
}