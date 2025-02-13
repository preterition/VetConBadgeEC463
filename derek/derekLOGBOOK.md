# Senior Design Session 1 Logbook.

Copyright Year 2021 Derek Deoliveira Barbosa dbarbosa@bu.edu
https://www.github.com/derekbarbosa
https://www.dbarbosa.net

## September
Entries here will be reserved specifically for the remainder of September.

### 9/20/2021
* Project Teams are assigned.
* Assigned to Team 32 -- VETCON BADGE
* Reviewed and began to interact with team members

### 9/21/2021
* Regrouped with team. Took team photos, decided to hold off on hitting the ground running until the following day

### 9/22/2021
* Started a Slack Workspace to manage group communication
	- Integrated BU Google Workspace Calendar into Slack Integrations
	- Started a Trello Board to manage project details, integrated to Slack
	- Created a Team Calendar to keep track of "who is in class" and facilitate the arrangement of meeting times.
	- Got in contact with client to arrange meeting time. Tentative for 9/24/2021 3PM Eastern.
	- Assigned the task of formulating questions for the client for further information on desired specifications to team members who would not be present during the inital cient meeting.

### 9/23/2021
* Finalized meeting details with our client. Confirmed for 9/24/2021 3pm eastern.
* Began drafting questions based on project requirements. Instructed group members to do the same.
* Set up a GH repo for our documentation. Linked to Slack Channel using webhooks to keep version control hygiene.

### 9/24/2021
* Met with clients! 
* attached notes for client meeting
* Ryan said he would take care of the inital PDRR writeup, will pause work for the weekend.

### 9/27/2021
* Brainstorming approach to IC/embedded system approach as described by client
* during review of the product specifications, clients emphasized battery life and weight
	* asked us to be somewhat conservative with the tradeoff
* started to look at TI-83/84 PCBs, determining best practices to create a low-power system with programmable memory.
* attaching notes to this upload :)

### 9/28/2021
* talk about rabbit hole research about calculators and low-power electronics
* Did a little more research on calculators and their "mini" operating system
	* this is following up on the design requirements from the client. They desired something that was "hackable" and easily "dumpable." They didn't need a "full" OS as we know today (Raspbian, etc) but would be fine with basic operating systems/firmware controller software.
	* Why so much research into calculators -- they are low power "embedded systems" that run off of AA batteries (less than 1100 mAh) for months at a time, with built-in save state and sleep cycles. Programmable Memory + ROM combination with fast (near instant) boot times.
	* Specifically looking into implementing KnightOS, a FOSS calculator OS that can run on TI-83/84s.
	* TI-83/84/84plus/84CE run on Zilog Z80, same processor in the old Sinclair Computers and other older computing systems. Easy to breadboard and fairly understandable datasheet compared to more modern microprocessors. Fairly straightforward ASM implementation as well if any need to get "manual" with the code.

* Much harder than just plugging in a Raspberry Pi Zero/Zero-W and calling it a day. But you get massive flexibility tradeoff + battery life
	* RPI consumes 1A with a few plugins/accessories running, would need 120WH battery (bigger than FAA/FCC limit) to power the device for 24 hours
	* RPI allows for easy compatiability with COTS components and rpi-approved "hats" out of GPIO plugins
	* benefit of working with linux kernel directly + debian-based OS tools.

* Met with Team -- reviewed the zoom call notes and discussed the approaches above. 
* Assigned John Kircher as the Team Leader for the first rotation. He will be working on the PDRR. I will contribute to the slide deck.

## October
Entries here will be reserved specifically for the month of October.

### 10/1/2021

* Researched ISA/Microprocessor compatability with KnightOS and Espilon OS (open source "calculator" operating systems that can be forked and edited for specific functionality.

* Began to look into parts ordering, accounting for 50 dollar budget.

* Created a slides template for the PDRR review


### 10/3/2021
* Preparing for PDRR initial presentation 10/7
* Not many new updates -- quick tag-up with team about next steps and what "we want to do" with our lead time
* Reviewed Presentation slides and script, made some edits to specifications
* Began working on PDRR written report

### 10/5/2021
* Attempted to find an easier middle ground between high-power (but flexible) SBC (single-board-computer) such a rasberry PI and manually soldering together an MCU and ROM.
* Encountered complete "embedded" development kits, closer to an SOC (think Arduino Uno's ATMEGA MCU / ESP32) but with an emphasis on ultra-low power consumption without entirely sacrificing QoL IDE tools
	* Board(s) of question: Texas Instruments "LaunchPad" development kits for the ultra-low power MSP430 MCU family -- https://www.ti.com/design-resources/embedded-development/hardware-kits-boards.html#launchpad
* Why this approach? 
	* As mentioned in the bullet above, Power Consumption is something our team needs to account for at all time.
	* The MSP430 famiy consumes 1.3 µA on average, and can still send enough power to "juice" a LFR display.
	* "mini" or "micro" MCU devkits allow us to have a consistent environment to prototype our code if we decide to just use an MSP430 and ROM soldered directly onto a board.
	* Enables flexibility with IDEs and built-in code snippets for code re-use
	* Can also leverage other family of MCUs, such as the ESP32 family.
	* Specifically, the FireBeetle https://www.dfrobot.com/product-1590.html -- has a low power consumption of 0.011 mA.
* Next steps?
	* Do some research of sample projects using these DevKits -- what are some issues that developers run into when debugging these boards
	* Look at some other DefCon badges that leveraged Arduino/arduino-like SOCs (especially their open-source git repos)
	* Review datasheets and peripheral compatability
	* Relay research back to Client -- inform them of approach
	* Compare SOC approach vs SBC vs Bare-Metal
	* Look into reverse-engineering SOC into bare-metal PCB
  
### 10/8/2021
* Regrouped with Team -- agreed to vote on specific approach next monday.
* Discussed at length the pros+cons of each architecture, we described our preferences and laid out our "greivances"
* Relayed that we might not hit power consumption requirements if we follow up with RPI approach.
* Decided as a team to "take off" until after Indigenous People's Day

### 10/12/2021
* Team has decided to go with DevKit approach. I will put orders in for MSP420s (low power) and Arduno Minis (that can leverage the low-power settings)
* Will also put in an order for a Digital Multimeter, maybe some breadboards too (so they can arrive in time).
* Started drafting some sketches describing how we would program the SOC memory using the built-in IDEs provided to us.
* John released the first draft of our PDRR -- Started to revise and edit some of the content for the final review prior to submission

### 10/15/2021
* Started to review datasheets for the MSP420/430 programming specifications
* installed the Eclipse-based IDE and verified debugging functionality (IDE specific to the TI LaunchPad board)
* Gathering materials and slide decks to present to our client again this saturday.
* Putting in orders for additional LEDs and Breadboards -- looking into drafting some starter designs to meet the creative aspect of the assignment.
* Began to look for example code to pull "inspiration" about starter code.

### 10/18/2021
* Discussed upcoming "plan of attack" with team. Realigned goals and applied pivots to tasks.
* Established a variety of roles for the project:
	- Software
	- Power Consumption 
	- Hardware/PCB design
	- Hacking Minigame
* The four roles align somewhat well with the 5 teammembers, as we have a good mix of skills. I volunteered myself for SW debugging
* Discussed how to set up our inital dev cycles upon arrival of our hardware (TIMSP430).
* Filled in the rest of team on how/why we should consider meeting up once or twice a week to do merges and progress meetings (to align with agile fashion)
* Presented MVP to VETCON Client, edited slides to reflect Shark Tank Presentation.

### 10/20/2021
* Hardware has officially arrived!
* Touched up the PDRR report
* revised our slides for Shark Tank
* Received excellent manufacturing advice from transitioning from SOC --> Custom PCB with MCUs, got the contact info of a manufacturer
* Received advice to leverage security exploits on ISA/MCU architecture to bring "social attention" to the platform.
* Devised approach of working from individual application layers down to a platform/bootloader

### 10/21/2021
* Last logbook entry before due date!
* Looking into setting up our CI/CD and pipeline hygiene, will set a workshop for Gherkin Model user story writing to "nail down" our functionality and describe "pin-pointed" features
* Looking into LCD libraries for TIMSP, and how to not only write sample code, but also flash binaries into the rom
* looking into creating a Basic Input Output System to control the memory management of the applications and inpit (BIOS).
  
### 10/26/2021
* First logbook entry for Logbook #2
* Set up a CI/CD Pipeline, officially all unstable code will be pushed to our invididual branches. Once functionality is confirmed, code will be merged to testing for debugging on secondary boards and then relesed to stable once we are satisfied and decide to start another function.
* Essentially team member scratchpads --> testing --> main
* Our First IDR went well, only feedback from Prof Osama was to bewary when opening up the repo and to ensure that there isn't too much involvement from the client side.
* Discussed logistics of Trello/Agile and User Story Writing using the gherkin model. Wrote a sample story to discuss how tackling solutions using "the smallest vertical slice" allows for concision and accuracy when describing functionality from a user perspective.
* Began to play around with some test code from TI and using TI dev tools. Got an LED to blink (our helloworld) and was able to wrtie scrolling text using the segmented display built into the evalutation board.
* Set up a meeting with the client to touch base and discuss project status. 
  
### 10/28/2021
* User story session 1! Wrote our first Epic. Epic #1, Gilgamesh, has 4 user stories which focus on the inital functioning of the badge, AKA "main menu" functionality.
	* Story 1: First Boot/Power On Sequence
	* Story 2: Main Menu and Bootloader
	* Story 3: Main Menu Navigation
	* Story 4: Program Execution and Return
* Trello Board link will be made public eventually!
* Along the way we also made the following design decisions:
	* Attempt to source another LCD module which will allow us to draw custom graphics.
	* If that doesn't pan out, either use the current LCD on the evaluation/development board AND use the badge itself as a "serial" console to PC/make an application that uses the terminal output as it's GUI.
* We also decided on the following roles
	* Derek & Ryan -- Software
	* Julia * John -- Cybersecurity and Display Modules
	* Carlos -- Design/Architecture
  
## November 
Entries here will be specifically reserved for the month of November.

### 11/2/2021
* Start of Sprint 1: My+Ryan's role is to interact with the bootloader for the MSP420.
* GIT Logs here:
	* adding bootloader to src -- COMMIT 10EAB35
	* adding mspboot and apps to repo -- COMMIT 01fb27c
	* cleaned up stuff. Deleted old objects and cloned samples of bootloader -- COMMIT 3ac7051
	* attempting to figure out what is going on with gmake compile errors -- COMMIT f322794
  
## 11/3/2021
* Rewriting <include> files to get the demo bootloader applications to function on non-windows systems
	* the demos written by the TI team were targeted for windows, so a lot of the dependency paths are written with "C:\" Win32 style NTFS directories rather than the standard Unix-like method of accessing directories from root "/usr/bin"
* Gmake continues to fail on compile, potential broken Gmake modules
* Build failures attributed to "all" target failing. I am suspecting that the built-in makefile may be broken.
* Came to realization that the demo files were written with an older version of the MSP compiler in mind, newer versions of the compiler break the "all" build rule in the makefile.
* Downloaded and installed a new version of the compiler, .c files are able to be compiled with succesful output.
* However, getting the bootloader to load and switch between two applications (at least with the demo files) is a bit of a complicated process:
	* For some reason, the demo requires us to compile the C code, which results in a .txt file being generated.
	* This .txt file needs to be copied to a certain directory for both applications (App1 and App2)
	* Once copied, the .bat (windows batch file) for some reason takes the .txt file and uses a python script to convert it back to C (weird, right?)
	* The both C files are then compiled down to one object and passed onto the bootloader. A host board is then required to flash the target board with the desired programs.
	* All in all, overcomplication for something that was supposed to be a bit more straightforward. The tutorial seemed to provide an example of how to provide OTA updates rather than focus on creating a bootloader.
* Ryan and I are scrapping this approach and will simply write our own self-contained bootloader that will simply be an application that calls different appications in memory.

### 11/4/2021
* First attempt at creating our own bootloader was highly unsuccesful. We were not able to compile code that was effective in getting anything done.
* Documented some issues with the TI Documentation. Decided to stop and focus on helping other teammembers complete their tasks.
* Assisted Carlos in getting KiCad reinstalled after major vulnerability expoit in the binary was leaked.
* Assisted John and Julian in getting their serial console to "print something"
* Set up a clean instance of the IDE back to a "hello world" state.

### 11/8/2021
* Met with Ryan to arrange time on Tuesday to get a headstart before prototypes, want some sort of "app loader" functional by Thursday.
* Played around with the LCDs and read up on datasheets to better understand them.

### 11/9/2021
* Discussed Upcoming Pre-Prototype plans and reviewed the assignments posted on Blackboard.
* Specifically, we discussed our challenges at hand (see previous logbook entries) and how we should potentially move to a simpler approach.
	* Discussed how we were not able to access the bootloader and rewrite "what was there" to reimplement our own - cause of concern for a few reasons
		1. We have NO idea now how much ROM is actually available to us since the BSL (base bootloader)
		2. Not sure how writing a simple App loader un top of the BSL will interact with memory
	* Texas Instrument's Documentation on the bootloader isn't great, actually flashing bootloader code is a very convoluted process that isn't friendly with other environments
	* Putting a large game alongside other applications will prove to be difficult. 
* Assisted Julian with getting serial output to print a Char Array.
	* Was difficult because we had to specifically manipulate a 16 bit register responible for the output stream
* Investigating the PlatformIO suite (https://platformio.org/) which would allow for easier debugging and monitoring of serial output for embedded system.
	* According to the documentation, the TI-MSP family is supported, specifically all of the EXP (launchpad) boards are suitable "targets" for the Plugin.
	* Because the plugin runs purely in Python, it is compatible on all environments -- suitable for use across the team and on VMs if needed.
	* Specifically, the PlatformIO plugin provides a flexible IDE in a modern environment (VSCode vs Proprietary Eclipse IDE)
	* The build process automatically tags SW dependencies and applies them automatically during the build stage, removing plenty of the compiler issues we were running into.
	* This could also help with the issue we're currently having: monitoring serial output consistently across dev machines (different environments handle USB comms differently) and allow us to create consistent output on our applications.
	* Warrants further investigation
  
### 11/11/2021
* Discovered serial output can be manipulated on the board by clearing, setting and flipping a 16 bit (2-byte) register.
	* Challenge presented: how to continually clear and set the output register with preprocessor directives.
	* Setting a outer while condition while iterating through the character bytestream did not prompt any success
* Carlos, responsible for PCB design asked what he could do in the meantime to "fill the void" while we pushed down the path of attempting to get communication functional on the board
	* I proposed he do our game development side of things, so far we have a Dino Run prototype going :)
* We decided to meet again the following day to get some more progress going
  
### 11/12/2021
* PlatformIO was super succesful! Writing serial output proved perfectly fine, and we are now able to import third party libraries with ease!
	* We can now print to console output and use board functionality
* One issue: Mapping of IO pins from the cross-compiler "environment" to the native pins on the board is a bit murky, so todays session was figuring out "what mapped to what"
* Otherwise, we are in the clear so far.
  
### 11/13/2021
* Met with the team over the weekend to do some more work in preparation for the prototype
* Set up Serial Interface loop, follows typial REPL methodology to parse user input and accept valid commands. Helper functions were established to jump to different locations in memory to execute desired functionalities.
* Added functionality to display text/ASCII graphics to serial monitor
* Attempted to include button functionality, ran into problems trying to get button inputs to "read" properly. Issues we had and suspicions are listed below
	* Button presses only worked properly within our void loop() function, which sits atop of the Return Stack Pointer on our call stack, so we suspected that buttons in functions that were called from loop() were consequentially "higher up" on our stack, and therefore unable to be properly "sampled."
	* Another suspicion we had, which was similar to the one above, was that the hardware could only be accessed in non-blocking functions, so we decided to write an interrupt that attached itself to a button pin, which ultimately proved unsuccesful 
* After attempting to correct button issue, we called it quits for the night.
  
### 11/15/2021
* Included button debouncing libraries to correct our input problems. Buttons are now able to be properly read albeit with very slight delay.
	* Why does this work? The buttons on the TIMSP430-EXPFR2433 specifically have "pullup" properties, meaning that the rising/falling edges aren't exactly "clean" and can't be reliable sampled. 
	* Including a debouncing library takes care of button "bounce" (i.e. what happens when you press and release a button) and accounts for the delay between presses.
* Took care of repo sanitization, testing branch is now up-to-date.
* Hosted Carlos' Dino game on Github Pages
  
### 11/16/2021
* added the URL to the webgame to our device!
* preparing for prototype testing

### 11/18/2021
* Prototype Testing went great, only feedback from Professor Osama was to "keep it up" and to continue to "have fun" with the project.
* Today we set new goals for until the "end of semester"
	* emphasis on polishing our software and our peripheral interfaces before we go into hardware design for the following semester.
	* allows us to focus on writing a better serial interface and providing "fun" interactivity with the badge.
* Roles have been reassigned for the remainder of the semester:
	* Derek -- web games
	* Carlos && Ryan -- memory interface
	* Julian -- Obfuscation of code
	* John -- LCD interface

## December
Entries here are reserved for December

### 12/2/21
* Finished the majority of our written tasks. No updates in logbook because of deadlines. Not much technical progress other than finishing PDR slides, individual reports, team contracts, video, etc.
* Began brainstorming potential scenarios for "verifying" communication between boards. Started work on BLE modules.

### 12/7/21 
* Began efforts to clean up GIT repos, pulled latest commits into some branches
* Continued drafting of final semester report. Assigned parts and gathered evidence/logs/info for said report.
* Discussed future semester plans with rest of team, discussed action items and reassessed "problem areas"
	* for example, discussing the worth of wireless communication and its compatibility with current approaches and tech stack.

### 12/11/21
* Report due tomorrow 9 AM, finished writing up technical plan/report (my section of it)
	* Highlighted the performance period and divided the major phases of technical development
	* Phase 2 has 3 tasks, ranging from a SW wrap up period to a circuit design schematic
	* Phase 3 is final integration, with system testing and packaging as the final tasks
* Taking hiatus from the project to rest up and recharge!

## END OF 1ST SEMESTER SENIOR DESIGN
Entries from this point are reserved for Spring Semester EC464

## January
Entries here are reserved for January
Note for reviewer: I already spoke to Professor Osama regarding this issue: but I forgot to push and commit my logbook over the Winter Break. The next few entries have NOT been backdated, but were just stored locally (not commited) due to my negligence. I will be linking documentation providing POW under each entry.

### 1/7/22 
* Contacted the rest of the team to begin preparations for upcoming semester
* Got in contact with the client as he requested an update/plan for a meeting the week of the 28th
(see screenshot labelled 1-7-21 attached)
 
### 1/20/22
* Team reconvened over slack/SMS to discuss upcoming deadlines.

### 1/25/22
* First "real" in-person team work session
* Ran into several issues with Bluetooth, current BT HW only programmable via CCStudio which we want to avoid as it is a problem for various reasons.
	* Currently, we are using PlatformIO, which works off TI's Wired Framework (a FOSS Framework) that is compatible with Arduino code. PlatformIO leverages this header from the Wiring Project that is currently used in TI's Ardunio/Wired IDE, Energia, and enables community code-snippets and "dependencies" for button debouncing/delay and etc (as mentioned before in this logbook)
	* Having the BLE/BT HW only programmable through CCStudio throws a wrench in our current tech-stack as there is no way we can (feasibly, with our time and skills) port over the Wiring Framework to a niche BT Device like ours. 
	* Currently, we plan on programming the full BT functionality through the device itself, flash it, and use it as a simple add-on to the main board as an "accessory" and nothing else. We are still drafting a better approach, that will require a bit more brainstorming.
	* Making progress on EEPROMs, just ordered a batch.
	* Info on Wiring here: https://github.com/WiringProject/Wiring 

### 1/26/22
* Pulled sample code of "coin flip" game the idea/plan-of-execution is the following:
	* User goes to coin-flip website to receive secret code
	* User "flips" the coin.
	* User receives either-heads-or-tails, but no secret is delivered (obviously)
	* Secret code will be hidden as a cookie on the user's device, with a 50-50 chance that the code is the correct one, and not a red herring.
	* Code will be "hashed" within the cookie, if hashed correctly, the incorrect code will be apparent that it is incorrect.
	* Entering the incorrect code will wipe the EEPROMs and reset the badge progress. The correct code will advance the user's progress.
* Looking into how to store cookies on-browser with JS libraries.

## 1/27/22
* Worked on the Coinflip game. Have the basic HTML structure ready to go, still lacking cookie storage and need to develop a key for the hash.
* IDR today -- briefed Osama on our progress, he is pleased! :) 
	* Relayed our concerns with our bluetooth modules and conflict with current tech stack. May require a future pivot if things don't go well
* Continued to work on the coinflip game, fine tuning graphics and pulling sample code from internet (sources will be sited in that readme)

### 1/28/22
* Met with Mike -- relayed our concerns and frustrations, he understood them and assured us that we were on-track and meeting all of his requirements and specifications.
* Discussions about contingency plans if Bluetooth connection does not pan out.
	
### 1/31/22
* Referenced the mozilla docs https://developer.mozilla.org/en-US/docs/Web/API/document/cookie for incorporating cookies into our webgame
* Editing source code to make it more *unique* to our project, including handling for cookie setting/resetting
	
## February
Entries here are reserved for February	

### 2/3/22
* Finished the Webgame! The source code will be available at github.com/derekbarbosa/EC463Webgames2

### 2/8/22
* Started game 3! Text based adventure written in CPP
* Managed to directly write to the board's FRAM, makes it easier to store programs for future use. Able to get persistent memory between various boot sessions.
* Began to brainstorm game 4 alongside game 3 development... suprise for now :) but will involve data recovery and various cybersecurity "red herrings"
* Still pursuing bluetooth debugging, with eventual conversion to platformio in the works.

### 2/10/22
* Continued to work on game 3, so far, here is the design "schema"
	* console-based text game, written in CPP
	* "time-based" activities -- each action consumes a "unit" of time, if you run out of time you lose
	* You are tasked with an objective, the game takes place over a day, and you must complete smaller, cascading tasks to reach the final "goal"
	* Very akin to the early-90s style text-based "choose your own adventure" game.
	* Signficiant less "cybersecurity" focus than the other games. This game is more geared towards confusing "multiple pathways".
* Regarding the technical structure of the game:
	* Core functions file with corresponding .cpp to flesh out core functionalities
	* Main game loop handled in game.cpp
	* user input will be grabbed and santiized in the same way, using a "grab" function to main consistent santization
	* every "action" reduces the time counter by a set amount based on initial decision
* Adding support for multiple pathways (eventually) and multiple endings. Only the "best ending" will print the code 

### 2/15/22
* Chrono support added, program is able to sleep/stop on demand
* Continued work on fleshing out functionalites for IDR this thursday

### 2/16/22 
* Finished "skeleton" of game 3 -- all structures and inits are tested and fleshed out.
* moving on to writing text based scenarios 

### 2/18/22
* Spent the day with the team brainstorming "scenarios" for the text-based game
* Game style will be similar to "Reigns" -- see the link here: https://reignsgame.com/
	* instead of being a "king" you are a BU student, trying to navigate through the semester and manage your four attributes
    	* Money
      	* Social
      	* Grades
      	* Health
  	* If any of these get too low, you lose!
* See previous notes for info on "update" functions for updating stats and user profiles
* Text-based scenarios will be fed through, parsed and set up in a "linked-list" structure
* IDs pertaining to each scenario will determine stats/choices.


### 2/22/22
* Edited file headers, light code refactors. Investigating how to parse textfile to feed into structs.

### 2/24/22
* Importing .xlsx to TSV (tab separated csv) and using getline() with 't' delimiter. 
* Created structs with proper IDs to feed text into scenario.
* Almost complete with game 3 :) 

### 2/25/22
* Running into a weird heap memory error. Attempting to debug by initalizing memory with class constructor
* Pushing code up for Ryan to help debug. GDB is broken on MacOS

### 2/27/22
* Even after some refactors, initializing memory in a separate CPP file is causing segfaults to occur when accessing said ptr in game.cpp (main)
* Doesn't occur when dereferencing memory that is allocated in main. 
* Weird behavior considering that both instances of mem are allocated on the heap and therefore can be accessed by dereferencing, rather than on the stack.

### 2/28/22
* Continued investigation of the segfaults yield no results. Will attempt to brute force by manually allocating in mem.

## March
Entries here are reserved for March	

### 3/1/22
* Bugfixes with multi-level pointers across files. Passed pointers by reference using "&" and dereferenced using, mistake made between passing pointer-to-value and passing pointer to pointer to value.
* Cleaned up value parsing with Getline. Points and point values are now completely parsed on the backend with string matching, stringstreams and getlines.
* Added support for point calculation and parsing persistent point values to front-end game loop
* finished global update function which calculates points & etc.

### 3/2/22
* Added support for multiple endings within game, different outcomes occur based on point values of each attribute of the "User Profile"
* Increased game difficulty, no longer *easy* to do the game in one complete run.
* Added persistent point support. Persistent flags now trigger a continuous increase/decrease in point valuation. 
* Fixed some formatting oddities.
* Game is complete and in "production mode" as of today! 
* Moving onto HW, testing power consumption of prototype

### 3/3/22
* Merging my branch into testing
* Cleaned merge conflicts

### 3/4 to 3/26/22
* Playing some catchup with logbooks because it was an eventful few weeks.
* Lots of EC464 busywork, prevented me from updating this the way I should have.
* 3/5 to 3/14 was Spring Break, so not many updates between those two dates.
* 3/15/22 - began testing power consumption of MSP and semi-completed circuit. Determining draw of circuit to account for the 20-hour battery life of device as specified in client requirements. Preparing for CDR presentation by tying up loose ends (bluetooth and code "ciphers").
* 3/17/22 -- Bluetooth in working state! Working on presentation for CDR, small work/regroup session afterwards.
* 3/21/22 - Ditched addressable LCD for a 16x2 Segmented LCD for ease-of-use. Addressable LCD refuses to play well with MSP headers. Prototype and "hello world" completed. Intialized LCD class/objects in codebase as well as some function prototypes for user-functionality. 
* 3/22/22 - Updated our client on progress so far:
  * Software Portion Complete/Polished and in-working state
  * Bluetooth Functional
  * Games 1-3 finished
  * Persistent State
  * Serial Communication Complete
  * Hardware -- mapping pins to schematic for PCB preliminary design
  * User Manual/Budget -- Device is on track to be sub-50 dollars. User manual due following Friday.
* Determined battery life of complete prototype (LCD, BT, multiple LEDs) w/ 500mAH 9v battery is 3-ish hours. Looking into NiMH batteries to provide desired capacity.
* 3/23/22 -- Investigating using automated main/rechargable battery switching with LiPo charging ICs (TP5410 and 4506)
* 3/24/22 -- User Manual draft complete, submitted.
* 3/25/22 -- Investigating flashing firmware.bin files without need for source code!
* 3/26/22 -- Updated logbooks to reflect progress made


### 3/28/22
* Day dedicated to writing out final testing plan
  
### 3/29/22
* Final testing. 
* Professor Pisano and Professor Osama had requested, that for ECE Day, we modify our material as a "learning course" or bootcamp to be more attractive to passerbys
* No other updates. Slight code refactors. 
* Began Power consumption testing w/ completed circuit and NiMH 2800 mAh batteries

### 3/30/22
* Battery results were promising! 15-16 hours out of 3x 2800 1.2v batteries from NiMH in AA form factor.
* Some other battery stats from testing
  
* Remolded Stats:

	*Using 500mAh 9 volt battery 
	*Lasting around 3 - 4 hours
	*Circuit consumption: 125mA - 160mA drain.

	*Using 350mAh 3.7 volt battery
	*Lasting around 2 - 3 hours
	*Circuit consumption: 120mA - 175mA drain

	*Using 3x 2800mAh 1.2 volt batteries in series: (3.6 volts)
	*Lasting around 15 - 16 hours
	*Circuit Consumption: 175mA - 185mA drain

* Here is where we are at:

* Today I refactored the code on my branch to lessen power consumption. 
* By replacing delay() with sleep() we are able to enter a lower power state on the board and draw less milliamps
* With this, I had the idea of creating an LED control menu. 
* It is assigned to key ‘9’ once all secrets are unlocked. 
* Here, users are able to choose to to turn off their LEDs, enter a ‘wave’ mode, ‘blink’ and ‘alternate blinking’ mode.
* The idea was to attach an interrupt to one of the push buttons and attach a startup routine to the interrupt call and make it so that the LED functions just keep looping over and over again until disrupted. 
* In the ‘OFF’ state we would just put the board in the lowest state, suspend() which draws little-to-no power, and in the other functions we would just have it microsleep to save power.
* The current issue is that we block and wait for serial at full power, but by doing the above we can circumvent that until i find a way to attach an interrupt routine to serial input. 
* some references:
  * https://embeddedcomputing.weebly.com/ultra-low-power-with-msp430.html
  * https://electronics.stackexchange.com/questions/228181/how-do-you-use-low-power-mode-on-an-msp430g2553-using-an-energia-sketch
  * https://forum.43oh.com/topic/8608-energia-ide-msp430f5529lp-low-power-mode/
  * https://energia.nu/reference/en/language/functions/time/delay/


### 3/31/22
* Meeting with client!
* Greenlight battery life, and green lit 'swappable' batteries as opposed to building a charge/boost/protect module into our circuit for time constraints.
* Spent more time attempting to program interrupts. No luck so far. Will reconfigure push buttons in attempt for power-save and customization control.
* Energia interrupts() detected properly outside of loop() (similar to issue at beginning of last semester), need to figure out how exactly im going to afford the user control over LED menu

## April
Entries here are reserved for April	

### 4/1/22
* Not many updates
* 18650 has 23 hours as of 5:00 pm. Fantastic
* Exploring options of moving game 3 code into docker container for higher cross-compat.

### 4/4/22
* Finished push-button and sleep() code, refactored/refined codebase and finished LED menu support
* Looking into adding physical toggle for LCD backlight
* began looking into enclosure manuf. for ECE day

### 4/5/22
* Upon further inspection, Button 2 is the only button onboard that does not have a 1-for-1 digital pin representation (pin 2.3) on the TI MSP430 EXP-FR2433 module
  * Refactored code to work solely off button 1. Slight changes in LCD menu logic to detect button1.pressed()
* Discussed PCB design with Julian and Carlos
* Began exploring resources for 3D-printing the enclosure for the MSP, PCB, Battery, LCD, and Switches.
* Began testing fit of a protoboard on the MSP. Plan is to create a makeshift "hat" for the MSP and pull all necessary leads from there.
  * Eventually final PCB design will be similar, but have resistors/LEDs pre-assembled on board.
  
### 4/7/22
* Wired a hardware circuit and refactored the code to work solely off button2 (pin 2.7). Physical push button wired to digital pin now works as intended.
* Tested some switches to cut off battery power, planning to append shottkey diode post-PCB
* On track to get schematic sent out this Friday