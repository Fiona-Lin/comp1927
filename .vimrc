set t_Co=256
syntax on
set background=dark
colorscheme distinguished

set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
Plugin 'nathanaelkane/vim-indent-guides'
Plugin 'scrooloose/syntastic'
let g:syntastic_check_on_open=1
let g:syntastic_javascript_checkers=['standard']
let g:syntastic_javascript_standard_exec = 'semistandard'
autocmd bufwritepost *.js silent !semistandard % --fix
set autoread

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
Plugin 'tpope/vim-fugitive'
Plugin 'jelera/vim-javascript-syntax'
Plugin 'pangloss/vim-javascript'
Plugin 'Raimondi/delimitMate'

" This does what it says on the tin. It will check your file on open too, not
" just on save.
" " You might not want this, so just leave it out if you don't.
let g:syntastic_check_on_open=1

" plugin from http://vim-scripts.org/vim/scripts.html
Plugin 'L9'
" Git plugin not hosted on GitHub
"Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
"Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
Plugin 'ascenator/L9', {'name': 'newL9'}
" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

Plugin 'marijnh/tern_for_vim'
Plugin 'Valloric/YouCompleteMe'

" These are the tweaks I apply to YCM's config, you don't need them but they
" might help.
" " YCM gives you popups and splits by default that some people might not
" like, so these should tidy it up a bit for you.
let g:ycm_global_ycm_extra_conf = "~/.vim/.ycm_extra_conf.py"
let g:ycm_key_list_select_completion=[]
let g:ycm_key_list_previous_completion=[]
let g:ycm_add_preview_to_completeopt=0
let g:ycm_python_binary_path = '/usr/bin/python3'
let g:ycm_python_binary_path = 'python'
let g:ycm_confirm_extra_conf=0
set completeopt-=preview



set expandtab
set shiftwidth=2
set softtabstop=2

autocmd FileType html setlocal shiftwidth=2 tabstop=2
autocmd FileType js setlocal shiftwidth=2 tabstop=2
autocmd FileType python setlocal expandtab shiftwidth=4 softtabstop=4
autocmd FileType c setlocal expandtab shiftwidth=4 softtabstop=4

highlight ExtraWhitespace ctermbg=red guibg=red
match ExtraWhitespace /\s\+$/
autocmd BufWinEnter * match ExtraWhitespace /\s\+$/
autocmd InsertEnter * match ExtraWhitespace /\s\+\%#\@<!$/
autocmd InsertLeave * match ExtraWhitespace /\s\+$/
autocmd BufWinLeave * call clearmatches()
