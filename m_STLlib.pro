TEMPLATE = app
CONFIG += console
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++0x


SOURCES += \
    String.cpp \
    Object.cpp \
    my_lib.cpp \
    Exception.cpp

OTHER_FILES += \
    m_STLlib.pro.user

HEADERS += \
    TreeNode.h \
    Tree_problem.h \
    Tree.h \
    String.h \
    StaticStack.h \
    StaticQueue.h \
    StaticList.h \
    StaticLinkList.h \
    StaticArray.h \
    Stack.h \
    Sort.h \
    SmartPointer.h \
    SharedPointer.h \
    SeqList.h \
    Queue.h \
    QueenSolution.h \
    Pointer.h \
    Object.h \
    MatrixGraph.h \
    ListGraph.h \
    List.h \
    LinuxList.h \
    LinkStack.h \
    LinkQueue.h \
    LinkList_sptr.h \
    LinkList.h \
    GTreeNode.h \
    GTree.h \
    Graph.h \
    Exception.h \
    DynamicList.h \
    DynamicArray.h \
    DualStaticLinkList.h \
    DualLinkList.h \
    DualCircleList.h \
    CircleList.h \
    BTreeNode.h \
    BTree.h \
    Array.h \
    algorithm-problem.h

