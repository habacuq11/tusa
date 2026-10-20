#include "mainwindow.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSlider>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    {
        resize(900,600);
        setWindowTitle("Tusa");
        auto* container = new QWidget(this);
        auto* exteriorLayout = new QVBoxLayout;
        auto* mainlayout = new QHBoxLayout;
        auto* playerBar = new QWidget;
        container->setLayout(exteriorLayout);
        exteriorLayout->addLayout(mainlayout);
        exteriorLayout->addWidget(playerBar);
        setCentralWidget(container);
        auto* biblioteca = new QWidget;
        auto* mainpanel = new QWidget;
        auto* blayout = new QVBoxLayout;
        auto* mplayout = new QVBoxLayout;
        biblioteca->setLayout(blayout);
        mainpanel->setLayout(mplayout);
        mainlayout->addWidget(biblioteca, 27);
        mainlayout->addWidget(mainpanel, 73);
        biblioteca->setObjectName("sidebar");
        mainpanel->setObjectName("mainpanel");
        blayout->addWidget(new QLabel("LIBRARY"));
        blayout->addWidget(new QLabel("MUSIC"));
        blayout->addWidget(new QLabel("ARTISTS"));
        blayout->addWidget(new QLabel("ALBUMS"));
        blayout->addWidget(new QLabel("PLAYLISTS"));
        blayout->addWidget(new QLabel("SPOTIFY"));
        auto* sectionTitle = new QLabel("MUSIC");
        auto* trackTitle = new QLabel("No song selected");
        auto* trackMetadata = new QLabel("Select a track from your library");
        auto* coverContainer = new QWidget;
        auto* coverLayout = new QVBoxLayout(coverContainer);
        sectionTitle->setObjectName("sectionTitle");
        trackTitle->setObjectName("trackTitle");
        trackMetadata->setObjectName("trackMetadata");
        mplayout->addWidget(sectionTitle);
        mplayout->addWidget(coverContainer);
        mplayout->addWidget(trackTitle);
        mplayout->addWidget(trackMetadata);
        coverContainer->setMinimumSize(220, 220);
        playerBar->setMinimumHeight(80);
        auto* playerLayout = new QHBoxLayout(playerBar);
        auto* songInfo = new QLabel("No song selected");
        auto* backButton = new QPushButton("|<");
        auto* playButton = new QPushButton(">");
        auto* nextButton = new QPushButton(">|");
        auto* rTime = new QLabel("0:00 / 0:00");
        auto* volume = new QLabel("Volume");
        auto* volumeSlider = new QSlider(Qt::Horizontal);
        volumeSlider->setRange(0, 100);
        volumeSlider->setValue(70);
        playerLayout->addWidget(songInfo);
        playerLayout->addWidget(backButton);
        playerLayout->addWidget(playButton);
        playerLayout->addWidget(nextButton);
        playerLayout->addWidget(rTime);
        playerLayout->addWidget(volume);
        playerLayout->addWidget(volumeSlider);
        songInfo->setObjectName("songInfo");
        backButton->setObjectName("backButton");
        playButton->setObjectName("playButton");
        nextButton->setObjectName("nextButton");
        rTime->setObjectName("playbackTime");
        volume->setObjectName("volumeLabel");
        volumeSlider->setObjectName("volumeSlider");
    }
MainWindow::~MainWindow() = default;