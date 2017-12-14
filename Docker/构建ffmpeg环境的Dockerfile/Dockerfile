FROM ubuntu:basis

RUN mkdir -p ~/ffmpeg_sources && \

# 编译安装NASM（一些库使用的汇编程序）
    cd ~/ffmpeg_sources && \
    wget http://www.nasm.us/pub/nasm/releasebuilds/2.13.01/nasm-2.13.01.tar.bz2 && \
    tar -xjvf nasm-2.13.01.tar.bz2 && \
    cd nasm-2.13.01 && \
    ./autogen.sh && \
    ./configure && \
    make && \
    make install && \ 

# 编译安装Yasm （一些库使用的汇编程序）
    cd ~/ffmpeg_sources && \
    wget -O yasm-1.3.0.tar.gz http://www.tortall.net/projects/yasm/releases/yasm-1.3.0.tar.gz && \
    tar xzvf yasm-1.3.0.tar.gz && \
    cd yasm-1.3.0 && \
    ./configure && \
    make && \
    make install && \

# 编译安装libx264 （H.264视频编码器）
    cd ~/ffmpeg_sources && \
    git -C x264 pull 2> /dev/null || git clone --depth 1 http://git.videolan.org/git/x264 && \
    cd x264 && \
    ./configure --enable-static && \
    make && \
    make install && \

# 编译安装libfdk-AAC（AAC音频编码器）
    cd ~/ffmpeg_sources && \
    git -C fdk-aac pull 2> /dev/null || git clone --depth 1 https://github.com/mstorsjo/fdk-aac && \
    cd fdk-aac && \
    autoreconf -fiv && \
    ./configure --disable-shared && \
    make && \
    make install && \

# 编译安装FFmpeg
    cd ~/ffmpeg_sources && \
    wget -O ffmpeg-snapshot.tar.bz2 http://ffmpeg.org/releases/ffmpeg-snapshot.tar.bz2 && \
    tar xjvf ffmpeg-snapshot.tar.bz2 && \
    cd ffmpeg && \
    ./configure \
        --extra-libs="-lpthread -lm" \
        --enable-gpl \
        --enable-libass \
        --enable-libfdk-aac \
        --enable-libfreetype \
        --enable-libtheora \
        --enable-libvorbis \
        --enable-libx264 \
        --enable-nonfree && \
    make && \
    make install && \
    rm -rf ~/ffmpeg_sources
    

