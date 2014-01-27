OBJ				=	obj
BIN				=	bin
VPATH			=	src
CXXFLAGS		=	-I	"./include"	-I	"./API/include"
CXXLIBDIR		=	-L	"./API/lib"
LIB_FLAGS		=	-lfreeglut	-lopengl32	-lglu32
PROGRAM_NAME	=	Snake2D
CHK_DIR_EXIST	=	if not exist
MKDIR         	=	mkdir
REN				=	ren


CPPFILES	=	$(wildcard	$(VPATH)/*.cpp)
OBJFILES	=	$(addprefix	$(OBJ)/,$(notdir	$(CPPFILES:.cpp=.o)))

all: createdir $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJFILES)
	$(CXX)	$(OBJFILES)	-o	$(BIN)/$@	$(CXXLIBDIR)	$(LIB_FLAGS)
	
$(OBJ)/%.o: $(VPATH)/%.cpp
	$(CXX)	-c	$(CXXFLAGS)	$<	-o	$@
	
	
clean:
	del $(OBJ)\*.o
	del $(BIN)\*.exe
	rmdir $(OBJ)
	rmdir $(BIN)
	

#bin ve obj dosyaları varsa bile yeniden oluşturmaz yoksa oluşturur..
#kontrolü @$(CHK_DIR_EXIST) yani "if not exist" ile ve peşinden dosya yolu yada dosya ismi verilerek kontrol edilir..
createdir:
	@$(CHK_DIR_EXIST)	$(OBJ)	$(MKDIR)	$(OBJ)
	@$(CHK_DIR_EXIST)	$(BIN)	$(MKDIR)	$(BIN)