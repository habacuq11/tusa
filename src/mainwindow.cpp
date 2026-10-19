#include "mainwindow.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

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
        auto* sectiontitle = new QLabel("MUSIC");
        auto* tracktitle = new QLabel("No song selected");
        auto* trackmetadata = new QLabel("Select a track from your library");
        auto* coverContainer = new QWidget;
        auto* coverLayout = new QVBoxLayout(coverContainer);
        sectiontitle->setObjectName("sectiontitle");
        tracktitle->setObjectName("tracktitle");
        trackmetadata->setObjectName("trackmetadata");
        mplayout->addWidget(sectiontitle);
        mplayout->addWidget(coverContainer);
        mplayout->addWidget(tracktitle);
        mplayout->addWidget(trackmetadata);
        coverContainer->resize(220, 220);
        playerBar->setMinimumHeight(80);
        auto* playerLayout = new QHBoxLayout(playerBar);
        auto* songInfo = new QLabel("No song selected");

    }
MainWindow::~MainWindow() = default;