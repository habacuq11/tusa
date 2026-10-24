//Code 100% write by hand by me (@habacuq11)
//This is a music player write in C++ with Qt :3
//some of this comments are temporary and will be removed later, I just put them cause I didn't know what I was doing atp 

//Includes
#include "mainwindow.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QUrl>

QMediaPlayer* player = new QMediaPlayer;//Creates the media player
QAudioOutput* audioOutput = new QAudioOutput;//Creates the audio output

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    {
        resize(900,600);//Sets the size of the window
        setWindowTitle("Tusa");//Sets th title of the window
        auto* container = new QWidget(this);//Creates a container for the window
        auto* exteriorLayout = new QVBoxLayout;//Creates a vertical layout for the container
        auto* mainlayout = new QHBoxLayout;//Creates a horizontal layout for the content or something like that lol idk how to explain
        auto* playerBar = new QWidget;//Creates a widget that is used as container for the player bar
        player->setAudioOutput(audioOutput);//Sets the audio output for the media player
        container->setLayout(exteriorLayout);//Adds  the vertical layout to the container PD: I really miss her :(
        exteriorLayout->addLayout(mainlayout);//Adds the horizontal layout to the vertical layout
        exteriorLayout->addWidget(playerBar);//Adds the player bar at the bottom of the vertical layout
        setCentralWidget(container);//Puts the container in the center
        auto* biblioteca = new QWidget;//Creates a container for the sidebar
        auto* mainpanel = new QWidget;//Creates the containere for the main panel
        auto* blayout = new QVBoxLayout;//Creates a vertical layout for the sidebar
        auto* mplayout = new QVBoxLayout;//Creates a vertical layout for the main panel
        biblioteca->setLayout(blayout);//Adds the vertical layout to the sidebar
        mainpanel->setLayout(mplayout);//Adds a vertical layout to the main panel
        mainlayout->addWidget(biblioteca, 27);//Adds the sidebar to the main horizontal layout and sets 27% of the layout for the sidebar 
        mainlayout->addWidget(mainpanel, 73);//Adds the main panel to the main layout just after the sidebar and sets 73% of the space for it
        biblioteca->setObjectName("sidebar");//Sets the ON (object name) "sidebar" to the sidebar (biblioteca)
        mainpanel->setObjectName("mainpanel");//Sets th ON "mainpanel" to the main panel
        blayout->addWidget(new QLabel("LIBRARY"));//Creates and add a new label wiht the text library yo the sidebar layout
        blayout->addWidget(new QLabel("MUSIC"));//Creates a new label with text music and add it to the sidebar layout
        blayout->addWidget(new QLabel("ARTISTS"));//Again creates a new label and add it to the side bar panel PD: Im getting bored writting this comments
        blayout->addWidget(new QLabel("ALBUMS"));//New label then add it to the sidebar layout
        blayout->addWidget(new QLabel("PLAYLISTS"));//New label then sidebar layout
        blayout->addWidget(new QLabel("SPOTIFY"));//New label then sidebar again PD: I hope this will be usefull for me or someone else
        auto* sectionTitle = new QLabel("MUSIC");//Creates a label and named it section Title
        auto* selectSong = new QPushButton("select a song uwu (just for proves)");
        auto* trackTitle = new QLabel("No song selected");//Creates a new label named trackTitle
        auto* trackMetadata = new QLabel("Select a track from your library");//Creates a new label named trackMetadata for the album and artist or something i dont remember
        auto* coverContainer = new QWidget;//Creates a new widget as container for the cover
        auto* coverLayout = new QVBoxLayout(coverContainer);//Creates a new vertical layout and assigns the cover container as father
        auto* coverPlaceholder = new QLabel("Album Artwork");//Creates a new label for the cover
        coverPlaceholder->setObjectName("coverPlaceholder");//Sets the ON for the cover label
        coverLayout->addWidget(coverPlaceholder, 1, Qt::AlignCenter);//Adds the cover label to the cover layout and sets all the space for it plus it align it to the center
        sectionTitle->setObjectName("sectionTitle");//Sets the ON of scetionTitle
        trackTitle->setObjectName("trackTitle");//Sets the ON of trackTitle
        trackMetadata->setObjectName("trackMetadata");//Sets the ON for trackMetadata
        mplayout->addWidget(sectionTitle);//Adds sectionTitle to the main panel
        mplayout->addWidget(selectSong);
        mplayout->addWidget(coverContainer);//Adds the cover container to the main panel
        mplayout->addWidget(trackTitle);//Adds trackTitle to the main panel
        mplayout->addWidget(trackMetadata);//Adds trackMetadata to the main panel 
        coverContainer->setMinimumSize(220, 220);//Sets the minimum size of the cover (220px x 220px)
        playerBar->setMinimumHeight(80);//Sets the minimumheight of the player bar 80px
        playerBar->setObjectName("playerBar");//sets the ON of the player bar
        auto* playerVLayout = new QVBoxLayout(playerBar);//Creates a new vertical layout and sets the player bar as fathr
        auto* progressContainer = new QWidget;//A container for the progress layout
        auto* progressLayout = new QHBoxLayout(progressContainer);//Creates a horizontal for the progress bar and the info
        auto* controlIContainer = new QWidget;//A container for player h layout
        auto* playerHLayout = new QHBoxLayout(controlIContainer);//Creates a new horizontal layout for the player bar
        auto* songInfo = new QLabel("No song selected");//Creates a label for the music info
        auto* backButton = new QPushButton("|<");//Creates the back button
        auto* playButton = new QPushButton(">");//Creates the play button
        auto* nextButton = new QPushButton(">|");//Creates the next button
        auto* rTime = new QLabel("0:00");//Creates a label for the reproduction time
        auto* tTime = new QLabel("0:00");//Creates a label for the transcurred time
        auto* volume = new QLabel("Volume");//A label for the volume info
        auto* volumeSlider = new QSlider(Qt::Horizontal);//Creates a horizontal slider to set the volume
        volumeSlider->setRange(0, 100);//Sets the slider range
        volumeSlider->setValue(70);//Sets the slider to a inittial value of 70
        auto* progressBar = new QSlider(Qt::Horizontal);//Creates another horizontal slider for the song progress
        progressBar->setObjectName("progressBar");//set the slider ON
        progressBar->setRange(0, 1000);//Set the slider range
        progressBar->setValue(0);//Sets the inittial value of the slider to 0
        auto* reproductionZone = new QWidget;//Creates a new container for the control buttons 
        reproductionZone->setObjectName("reproductionZone");//Set the ON for the coontainer
        auto* reproductionLayout = new QHBoxLayout(reproductionZone);//Creates a horizontal layout for the button container
        playerVLayout->addWidget(progressContainer);//Adds the progress container at the top
        playerVLayout->addWidget(controlIContainer);//Adds the control i container at the bottom
        progressLayout->addWidget(tTime);//Adds the transcurred time
        progressLayout->addWidget(progressBar);//Adds the progress bar to the progress layout
        progressLayout->addWidget(rTime);//Adds the total reproduction time
        playerHLayout->addWidget(songInfo);//Adds the song info to the main layout of the player bar
        playerHLayout->addStretch();//adds flexible space 
        playerHLayout->addWidget(reproductionZone);//Adds the button container to the playerbar layout
        reproductionLayout->addWidget(backButton);//Adds the back button to the button container
        reproductionLayout->addWidget(playButton);//Adds the button to the button container
        reproductionLayout->addWidget(nextButton);//Adds the button to the button container
        playerHLayout->addWidget(volume);//Adds the volume info to the player bar layout
        playerHLayout->addWidget(volumeSlider);//Adds the volume slider to the playerbar layout
        songInfo->setObjectName("songInfo");//Sets the ON of song Info
        backButton->setObjectName("backButton");//sets ON of the backbutton
        playButton->setObjectName("playButton");//sets the ON of the play Button
        nextButton->setObjectName("nextButton"); //sets the ON of the next button
        rTime->setObjectName("playbackTime");//sets the ON of the reproduction time
        volume->setObjectName("volumeLabel");//sets the ON of the volume info
        volumeSlider->setObjectName("volumeSlider");//sets the ON of the volume slider
        audioOutput->setVolume(volumeSlider->value() / 100.0);//Sets the volume slider value as the audio output volume
        connect(selectSong, &QPushButton::clicked, this, MainWindow::openFile);
    }

    void MainWindow::openFile(){
        QString file = QFileDialog::getOpenFileName(this, "Select song", "", "Audio (*.mp3, *.wav, *.flac);;All (*)");

        if(file.isEmpty()){
            return;
        };

        player->setSource(QUrl::fromLocalFile(file));
        QFileInfo info(file);
        QString name = info.baseName();
        player->play();

    }
MainWindow::~MainWindow() = default;// the destructor lol