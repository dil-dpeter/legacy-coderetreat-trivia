#include <iostream>
#include <list>
#include <vector>
#include <map>


using namespace std;

#ifndef GAME_H_
#define GAME_H_
#define CORRECTMSG "Answer was correct!"
#define HU 1
#define ENG 2
#define CHINESE 3
#define JAPANESE 4
#define GERMAN 5





#define  WELCOME_MSG 1
#define  GOODBYE_MSG  2
#define  ROLLMSG 3


class Game{
public:
	class literals {
	public:

		std::map<int, std::map<int, std::string>> m_lang_literal;
		literals()
		{

			m_lang_literal[ENG][WELCOME_MSG] = "Welcome";
			m_lang_literal[ENG][GOODBYE_MSG] = "Goodbye";
			m_lang_literal[ENG][ROLLMSG] = "They have rolled a ";


			m_lang_literal[HU][WELCOME_MSG] = "Udv";
			m_lang_literal[HU][GOODBYE_MSG] = "Viszlat";
			m_lang_literal[HU][ROLLMSG] = "Dobtak egy";

			m_lang_literal[GERMAN][WELCOME_MSG] = "Willkommen";
			m_lang_literal[GERMAN][GOODBYE_MSG] = "Auf Wiedersehen";
			m_lang_literal[GERMAN][ROLLMSG] = "Sie haben eine geworfen ";

			m_lang_literal[JAPANESE][WELCOME_MSG] = "ようこそ";
			m_lang_literal[JAPANESE][GOODBYE_MSG] = "さようなら";
			m_lang_literal[JAPANESE][ROLLMSG] = "彼らはロールしました ";

			m_lang_literal[CHINESE][WELCOME_MSG] = "欢迎";
			m_lang_literal[CHINESE][GOODBYE_MSG] = "再见";
			m_lang_literal[CHINESE][ROLLMSG] = "他们掷了一个 ";
		};


	
		

		std::string getMessage(int language, int messageId) const {
			auto langIt = m_lang_literal.find(language);
			if (langIt != m_lang_literal.end()) {
				auto msgIt = langIt->second.find(messageId);
				if (msgIt != langIt->second.end()) {
					return msgIt->second;
				}
			}
			return "Message not found";

		}
	} m_literals;


	class questions {
	public:
		questions() {
		};
		map<string, list<string>> qMap;
		void addQuestion(const std::string& theme, const std::string& question) {
			qMap[theme].push_back(question);
		}

		std::string getQuestion(const std::string& theme) {
			auto it = qMap.find(theme);
			if (it != qMap.end() && !it->second.empty()) {
				std::string question = it->second.front();
				it->second.pop_front();
				return question;
			}
			return "No questions available for this theme.";
		}
	private:
		list<string> popQuestions;
		list<string> scienceQuestions;
		list<string> sportsQuestions;
		list<string> rockQuestions;

	}m_questions;
		
public:
			vector<string> players;

			int places[10];
			int purses[10];
			int m_lang;

			bool inPenaltyBox[6];

			

			unsigned int currentPlayer;
			bool isGettingOutOfPenaltyBox;

public:
	Game();
	~Game();
	void setLang(int lang) {
	
		m_lang = lang;
	};
	string createRockQuestion(int index);

	bool isPlayable();
	bool add(string playerName);

	int howManyPlayers();
	void roll(int roll);

public:
	std::string getMessage(int id);
	void askQuestion();
		string currentCategory();

				public:
					bool wasCorrectlyAnswered();
					bool wrongAnswer();

public:
	bool didPlayerWin();

};

#endif /* GAME_H_ */
