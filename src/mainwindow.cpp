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
#include <QFileInfo>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    {
        resize(900,600);//Sets the size of the window
        setWindowTitle("Tusa");//Sets th title of the window
        MediaPlayer = new QMediaPlayer(this);
        AudioOutput = new QAudioOutput(this);
        auto* container = new QWidget(this);//Creates a container for the window
        auto* exteriorLayout = new QVBoxLayout;//Creates a vertical layout for the container
        auto* mainlayout = new QHBoxLayout;//Creates a horizontal layout for the content or something like that lol idk how to explain
        auto* playerBar = new QWidget;//Creates a widget that is used as container for the player bar
        MediaPlayer->setAudioOutput(AudioOutput);//Sets the audio output for the media player
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
        trackTitle_ = new QLabel("No song selected");//Creates a new label named trackTitle
        trackMetadata_ = new QLabel("Select a track from your library");//Creates a new label named trackMetadata for the album and artist or something i dont remember
        auto* coverContainer = new QWidget;//Creates a new widget as container for the cover
        auto* coverLayout = new QVBoxLayout(coverContainer);//Creates a new vertical layout and assigns the cover container as father
        auto* coverPlaceholder = new QLabel("Album Artwork");//Creates a new label for the cover
        coverPlaceholder->setObjectName("coverPlaceholder");//Sets the ON for the cover label
        coverLayout->addWidget(coverPlaceholder, 1, Qt::AlignCenter);//Adds the cover label to the cover layout and sets all the space for it plus it align it to the center
        sectionTitle->setObjectName("sectionTitle");//Sets the ON of scetionTitle
        trackTitle_->setObjectName("trackTitle");//Sets the ON of trackTitle
        trackMetadata_->setObjectName("trackMetadata");//Sets the ON for trackMetadata
        mplayout->addWidget(sectionTitle);//Adds sectionTitle to the main panel
        mplayout->addWidget(selectSong);
        mplayout->addWidget(coverContainer);//Adds the cover container to the main panel
        mplayout->addWidget(trackTitle_);//Adds trackTitle to the main panel
        mplayout->addWidget(trackMetadata_);//Adds trackMetadata to the main panel 
        coverContainer->setMinimumSize(220, 220);//Sets the minimum size of the cover (220px x 220px)
        playerBar->setMinimumHeight(80);//Sets the minimumheight of the player bar 80px
        playerBar->setObjectName("playerBar");//sets the ON of the player bar
        auto* playerVLayout = new QVBoxLayout(playerBar);//Creates a new vertical layout and sets the player bar as fathr
        auto* progressContainer = new QWidget;//A container for the progress layout
        auto* progressLayout = new QHBoxLayout(progressContainer);//Creates a horizontal for the progress bar and the info
        auto* controlIContainer = new QWidget;//A container for player h layout
        auto* playerHLayout = new QHBoxLayout(controlIContainer);//Creates a new horizontal layout for the player bar
        songInfo_ = new QLabel("No song selected");//Creates a label for the music info
        backButton_ = new QPushButton("|<");//Creates the back button
        playButton_ = new QPushButton(">");//Creates the play button
        nextButton_ = new QPushButton(">|");//Creates the next button
        rTime_ = new QLabel("0:00");//Creates a label for the reproduction time
        tTime_ = new QLabel("0:00");//Creates a label for the transcurred time
        volume_ = new QLabel("Volume");//A label for the volume info
        volumeSlider_ = new QSlider(Qt::Horizontal);//Creates a horizontal slider to set the volume
        volumeSlider_->setRange(0, 100);//Sets the slider range
        volumeSlider_->setValue(70);//Sets the slider to a inittial value of 70
        progressBar_ = new QSlider(Qt::Horizontal);//Creates another horizontal slider for the song progress
        progressBar_->setObjectName("progressBar");//set the slider ON
        progressBar_->setRange(0, 1000);//Set the slider range
        progressBar_->setValue(0);//Sets the inittial value of the slider to 0
        auto* reproductionZone = new QWidget;//Creates a new container for the control buttons 
        reproductionZone->setObjectName("reproductionZone");//Set the ON for the coontainer
        auto* reproductionLayout = new QHBoxLayout(reproductionZone);//Creates a horizontal layout for the button container
        playerVLayout->addWidget(progressContainer);//Adds the progress container at the top
        playerVLayout->addWidget(controlIContainer);//Adds the control i container at the bottom
        progressLayout->addWidget(tTime_);//Adds the transcurred time
        progressLayout->addWidget(progressBar_);//Adds the progress bar to the progress layout
        progressLayout->addWidget(rTime_);//Adds the total reproduction time
        playerHLayout->addWidget(songInfo_);//Adds the song info to the main layout of the player bar
        playerHLayout->addStretch();//adds flexible space 
        playerHLayout->addWidget(reproductionZone);//Adds the button container to the playerbar layout
        reproductionLayout->addWidget(backButton_);//Adds the back button to the button container
        reproductionLayout->addWidget(playButton_);//Adds the button to the button container
        reproductionLayout->addWidget(nextButton_);//Adds the button to the button container
        playerHLayout->addWidget(volume_);//Adds the volume info to the player bar layout
        playerHLayout->addWidget(volumeSlider_);//Adds the volume slider to the playerbar layout
        songInfo_->setObjectName("songInfo");//Sets the ON of song Info
        backButton_->setObjectName("backButton");//sets ON of the backbutton
        playButton_->setObjectName("playButton");//sets the ON of the play Button
        nextButton_->setObjectName("nextButton"); //sets the ON of the next button
        rTime_->setObjectName("playbackTime");//sets the ON of the reproduction time
        volume_->setObjectName("volumeLabel");//sets the ON of the volume info
        volumeSlider_->setObjectName("volumeSlider");//sets the ON of the volume slider
        volumeChanged(volumeSlider_->value());
        connect(selectSong, &QPushButton::clicked, this, MainWindow::openFile);
        connect(volumeSlider_, &QSlider::valueChanged, this, &MainWindow::volumeChanged);
        connect(playButton_, &QPushButton::clicked, this, &MainWindow::ppState);
        connect(MediaPlayer, &QMediaPlayer::positionChanged, this, MainWindow::posChanged);
        connect(MediaPlayer, &QMediaPlayer::durationChanged, this, MainWindow::durChanged);
        connect(progressBar_, &QSlider::sliderMoved, this, MainWindow::progressMoved);
    }


    void MainWindow::openFile(){
        QString file = QFileDialog::getOpenFileName(this, "Select song", "", "Audio (*.mp3 *.wav *.flac);;All (*)");

        if(file.isEmpty()){
            return;
        };

        MediaPlayer->setSource(QUrl::fromLocalFile(file));
        QFileInfo info(file);
        QString name = info.baseName();
        trackTitle_->setText(name);
        songInfo_->setText(name);
        MediaPlayer->play();
    }

    void MainWindow::ppState(){
        if(MediaPlayer->playbackState()==QMediaPlayer::PlayingState){
            MediaPlayer->pause();
            playButton_->setText(">");
        }else{
            MediaPlayer->play();
            playButton_->setText("||");
        }
    }

    void MainWindow::volumeChanged(int value){
        AudioOutput->setVolume(value / 100.0);
        volume_->setText(QString("Vol: %1%").arg(value));
    }

    static QString formatTime(qint64 ms){
        qint64 totalSecs = ms / 1000;
        qint64 mins = totalSecs / 60;
        qint64 secs = totalSecs % 60;
        return QString("%1:%2").arg(mins).arg(secs, 2, 10, QChar('0'));
    }

    void MainWindow::posChanged(qint64 pos){
        if(!progressBar_->isSliderDown()){
            progressBar_->setValue(static_cast<int>(pos));
        }
        tTime_->setText(formatTime(pos));
    }

    void MainWindow::durChanged(qint64 dur){
        progressBar_->setRange(0, static_cast<int>(dur));
        rTime_->setText(formatTime(dur));
    }

    void MainWindow::progressMoved(int value){
        MediaPlayer->setPosition(value);
    }
MainWindow::~MainWindow() = default;// the destructor lol