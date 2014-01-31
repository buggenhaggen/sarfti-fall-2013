




<!DOCTYPE html>
<html>
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# object: http://ogp.me/ns/object# article: http://ogp.me/ns/article# profile: http://ogp.me/ns/profile#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>sarfti-fall-2013/task_6/aggregation/aggregation.cpp at AnnPonomareva · vsysoev/sarfti-fall-2013</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-144.png" />
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144.png" />
    <meta property="fb:app_id" content="1401488693436528"/>

      <meta content="@github" name="twitter:site" /><meta content="summary" name="twitter:card" /><meta content="vsysoev/sarfti-fall-2013" name="twitter:title" /><meta content="sarfti-fall-2013 - SarFTI fall 2013 programming technology class " name="twitter:description" /><meta content="https://0.gravatar.com/avatar/8be3c09a4c313b12c80d9667a96c3baa?d=https%3A%2F%2Fidenticons.github.com%2Fa2195e5b065d9594c2a1069fe0a53786.png&amp;r=x&amp;s=400" name="twitter:image:src" />
<meta content="GitHub" property="og:site_name" /><meta content="object" property="og:type" /><meta content="https://0.gravatar.com/avatar/8be3c09a4c313b12c80d9667a96c3baa?d=https%3A%2F%2Fidenticons.github.com%2Fa2195e5b065d9594c2a1069fe0a53786.png&amp;r=x&amp;s=400" property="og:image" /><meta content="vsysoev/sarfti-fall-2013" property="og:title" /><meta content="https://github.com/vsysoev/sarfti-fall-2013" property="og:url" /><meta content="sarfti-fall-2013 - SarFTI fall 2013 programming technology class " property="og:description" />

    <meta name="hostname" content="github-fe139-cp1-prd.iad.github.net">
    <meta name="ruby" content="ruby 2.1.0p0-github-tcmalloc (87d8860372) [x86_64-linux]">
    <link rel="assets" href="https://github.global.ssl.fastly.net/">
    <link rel="conduit-xhr" href="https://ghconduit.com:25035/">
    <link rel="xhr-socket" href="/_sockets" />
    


    <meta name="msapplication-TileImage" content="/windows-tile.png" />
    <meta name="msapplication-TileColor" content="#ffffff" />
    <meta name="selected-link" value="repo_source" data-pjax-transient />
    <meta content="collector.githubapp.com" name="octolytics-host" /><meta content="collector-cdn.github.com" name="octolytics-script-host" /><meta content="github" name="octolytics-app-id" /><meta content="5104D260:5592:2C9559B:52EB99CF" name="octolytics-dimension-request_id" /><meta content="6329648" name="octolytics-actor-id" /><meta content="EvgeniiLydaev" name="octolytics-actor-login" /><meta content="4221d1e1f30ee42694d9471894cbd8a9680549e77843358775beaa7f3a98ac75" name="octolytics-actor-hash" />
    

    
    
    <link rel="icon" type="image/x-icon" href="/favicon.ico" />

    <meta content="authenticity_token" name="csrf-param" />
<meta content="I/3NsWlEhoufgGKObzq0tXJ4iEEqO6YQAzh8kRzkRZg=" name="csrf-token" />

    <link href="https://github.global.ssl.fastly.net/assets/github-ffe7e45502ed615bf3cb9cb1bbb7d0d32f095264.css" media="all" rel="stylesheet" type="text/css" />
    <link href="https://github.global.ssl.fastly.net/assets/github2-13805a78bc89e6b8baa64d96ee8bef168f18cedb.css" media="all" rel="stylesheet" type="text/css" />
    


      <script src="https://github.global.ssl.fastly.net/assets/frameworks-3e59bf2ccf0be318d5d920c2ab0bf1ab4cb3a96b.js" type="text/javascript"></script>
      <script async="async" defer="defer" src="https://github.global.ssl.fastly.net/assets/github-7b7c604b575b582c333f0745fdacb51b972cd638.js" type="text/javascript"></script>
      
      <meta http-equiv="x-pjax-version" content="658648d282bcc2be3e05884ea04fd5df">

        <link data-pjax-transient rel='permalink' href='/vsysoev/sarfti-fall-2013/blob/3452ce7f2227074b00781c09f28b84011d02df7f/task_6/aggregation/aggregation.cpp'>

  <meta name="description" content="sarfti-fall-2013 - SarFTI fall 2013 programming technology class " />

  <meta content="4449080" name="octolytics-dimension-user_id" /><meta content="vsysoev" name="octolytics-dimension-user_login" /><meta content="12573657" name="octolytics-dimension-repository_id" /><meta content="vsysoev/sarfti-fall-2013" name="octolytics-dimension-repository_nwo" /><meta content="true" name="octolytics-dimension-repository_public" /><meta content="false" name="octolytics-dimension-repository_is_fork" /><meta content="12573657" name="octolytics-dimension-repository_network_root_id" /><meta content="vsysoev/sarfti-fall-2013" name="octolytics-dimension-repository_network_root_nwo" />
  <link href="https://github.com/vsysoev/sarfti-fall-2013/commits/AnnPonomareva.atom" rel="alternate" title="Recent Commits to sarfti-fall-2013:AnnPonomareva" type="application/atom+xml" />

  </head>


  <body class="logged_in  env-production windows vis-public page-blob">
    <div class="wrapper">
      
      
      
      


      <div class="header header-logged-in true">
  <div class="container clearfix">

    <a class="header-logo-invertocat" href="https://github.com/">
  <span class="mega-octicon octicon-mark-github"></span>
</a>

    
    <a href="/notifications" class="notification-indicator tooltipped downwards" data-gotokey="n" title="You have no unread notifications">
        <span class="mail-status all-read"></span>
</a>

      <div class="command-bar js-command-bar  in-repository">
          <form accept-charset="UTF-8" action="/search" class="command-bar-form" id="top_search_form" method="get">

<input type="text" data-hotkey="/ s" name="q" id="js-command-bar-field" placeholder="Search or type a command" tabindex="1" autocapitalize="off"
    
    data-username="EvgeniiLydaev"
      data-repo="vsysoev/sarfti-fall-2013"
      data-branch="AnnPonomareva"
      data-sha="363deefc52ad5ab8573f55e145716b877558b7de"
  >

    <input type="hidden" name="nwo" value="vsysoev/sarfti-fall-2013" />

    <div class="select-menu js-menu-container js-select-menu search-context-select-menu">
      <span class="minibutton select-menu-button js-menu-target">
        <span class="js-select-button">This repository</span>
      </span>

      <div class="select-menu-modal-holder js-menu-content js-navigation-container">
        <div class="select-menu-modal">

          <div class="select-menu-item js-navigation-item js-this-repository-navigation-item selected">
            <span class="select-menu-item-icon octicon octicon-check"></span>
            <input type="radio" class="js-search-this-repository" name="search_target" value="repository" checked="checked" />
            <div class="select-menu-item-text js-select-button-text">This repository</div>
          </div> <!-- /.select-menu-item -->

          <div class="select-menu-item js-navigation-item js-all-repositories-navigation-item">
            <span class="select-menu-item-icon octicon octicon-check"></span>
            <input type="radio" name="search_target" value="global" />
            <div class="select-menu-item-text js-select-button-text">All repositories</div>
          </div> <!-- /.select-menu-item -->

        </div>
      </div>
    </div>

  <span class="octicon help tooltipped downwards" title="Show command bar help">
    <span class="octicon octicon-question"></span>
  </span>


  <input type="hidden" name="ref" value="cmdform">

</form>
        <ul class="top-nav">
          <li class="explore"><a href="/explore">Explore</a></li>
            <li><a href="https://gist.github.com">Gist</a></li>
            <li><a href="/blog">Blog</a></li>
          <li><a href="https://help.github.com">Help</a></li>
        </ul>
      </div>

    


  <ul id="user-links">
    <li>
      <a href="/EvgeniiLydaev" class="name">
        <img alt="EvgeniiLydaev" height="20" src="https://1.gravatar.com/avatar/57cceac4eeb4ceed9d06d7ee257bfddb?d=https%3A%2F%2Fidenticons.github.com%2F9831b1c0199266afe73db557e8fdad59.png&amp;r=x&amp;s=140" width="20" /> EvgeniiLydaev
      </a>
    </li>

    <li class="new-menu dropdown-toggle js-menu-container">
      <a href="#" class="js-menu-target tooltipped downwards" title="Create new..." aria-label="Create new...">
        <span class="octicon octicon-plus"></span>
        <span class="dropdown-arrow"></span>
      </a>

      <div class="js-menu-content">
      </div>
    </li>

    <li>
      <a href="/settings/profile" id="account_settings"
        class="tooltipped downwards"
        aria-label="Account settings "
        title="Account settings ">
        <span class="octicon octicon-tools"></span>
      </a>
    </li>
    <li>
      <a class="tooltipped downwards" href="/logout" data-method="post" id="logout" title="Sign out" aria-label="Sign out">
        <span class="octicon octicon-log-out"></span>
      </a>
    </li>

  </ul>

<div class="js-new-dropdown-contents hidden">
  

<ul class="dropdown-menu">
  <li>
    <a href="/new"><span class="octicon octicon-repo-create"></span> New repository</a>
  </li>
  <li>
    <a href="/organizations/new"><span class="octicon octicon-organization"></span> New organization</a>
  </li>


    <li class="section-title">
      <span title="vsysoev/sarfti-fall-2013">This repository</span>
    </li>
      <li>
        <a href="/vsysoev/sarfti-fall-2013/issues/new"><span class="octicon octicon-issue-opened"></span> New issue</a>
      </li>
</ul>

</div>


    
  </div>
</div>

      

      




          <div class="site" itemscope itemtype="http://schema.org/WebPage">
    
    <div class="pagehead repohead instapaper_ignore readability-menu">
      <div class="container">
        

<ul class="pagehead-actions">

    <li class="subscription">
      <form accept-charset="UTF-8" action="/notifications/subscribe" class="js-social-container" data-autosubmit="true" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="I/3NsWlEhoufgGKObzq0tXJ4iEEqO6YQAzh8kRzkRZg=" /></div>  <input id="repository_id" name="repository_id" type="hidden" value="12573657" />

    <div class="select-menu js-menu-container js-select-menu">
      <a class="social-count js-social-count" href="/vsysoev/sarfti-fall-2013/watchers">
        9
      </a>
      <span class="minibutton select-menu-button with-count js-menu-target" role="button" tabindex="0">
        <span class="js-select-button">
          <span class="octicon octicon-eye-unwatch"></span>
          Unwatch
        </span>
      </span>

      <div class="select-menu-modal-holder">
        <div class="select-menu-modal subscription-menu-modal js-menu-content">
          <div class="select-menu-header">
            <span class="select-menu-title">Notification status</span>
            <span class="octicon octicon-remove-close js-menu-close"></span>
          </div> <!-- /.select-menu-header -->

          <div class="select-menu-list js-navigation-container" role="menu">

            <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input id="do_included" name="do" type="radio" value="included" />
                <h4>Not watching</h4>
                <span class="description">You only receive notifications for conversations in which you participate or are @mentioned.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-eye-watch"></span>
                  Watch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item selected" role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input checked="checked" id="do_subscribed" name="do" type="radio" value="subscribed" />
                <h4>Watching</h4>
                <span class="description">You receive notifications for all conversations in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-eye-unwatch"></span>
                  Unwatch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input id="do_ignore" name="do" type="radio" value="ignore" />
                <h4>Ignoring</h4>
                <span class="description">You do not receive any notifications for conversations in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-mute"></span>
                  Stop ignoring
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

          </div> <!-- /.select-menu-list -->

        </div> <!-- /.select-menu-modal -->
      </div> <!-- /.select-menu-modal-holder -->
    </div> <!-- /.select-menu -->

</form>
    </li>

  <li>
  

  <div class="js-toggler-container js-social-container starring-container ">
    <a href="/vsysoev/sarfti-fall-2013/unstar"
      class="minibutton with-count js-toggler-target star-button starred upwards"
      title="Unstar this repository" data-remote="true" data-method="post" rel="nofollow">
      <span class="octicon octicon-star-delete"></span><span class="text">Unstar</span>
    </a>

    <a href="/vsysoev/sarfti-fall-2013/star"
      class="minibutton with-count js-toggler-target star-button unstarred upwards"
      title="Star this repository" data-remote="true" data-method="post" rel="nofollow">
      <span class="octicon octicon-star"></span><span class="text">Star</span>
    </a>

      <a class="social-count js-social-count" href="/vsysoev/sarfti-fall-2013/stargazers">
        0
      </a>
  </div>

  </li>


        <li>
          <a href="/vsysoev/sarfti-fall-2013/fork" class="minibutton with-count js-toggler-target fork-button lighter upwards" title="Fork this repo" rel="nofollow" data-method="post">
            <span class="octicon octicon-git-branch-create"></span><span class="text">Fork</span>
          </a>
          <a href="/vsysoev/sarfti-fall-2013/network" class="social-count">5</a>
        </li>


</ul>

        <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public">
          <span class="repo-label"><span>public</span></span>
          <span class="mega-octicon octicon-repo"></span>
          <span class="author">
            <a href="/vsysoev" class="url fn" itemprop="url" rel="author"><span itemprop="title">vsysoev</span></a>
          </span>
          <span class="repohead-name-divider">/</span>
          <strong><a href="/vsysoev/sarfti-fall-2013" class="js-current-repository js-repo-home-link">sarfti-fall-2013</a></strong>

          <span class="page-context-loader">
            <img alt="Octocat-spinner-32" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
          </span>

        </h1>
      </div><!-- /.container -->
    </div><!-- /.repohead -->

    <div class="container">
      

      <div class="repository-with-sidebar repo-container new-discussion-timeline js-new-discussion-timeline  ">
        <div class="repository-sidebar">
            

<div class="sunken-menu vertical-right repo-nav js-repo-nav js-repository-container-pjax js-octicon-loaders">
  <div class="sunken-menu-contents">
    <ul class="sunken-menu-group">
      <li class="tooltipped leftwards" title="Code">
        <a href="/vsysoev/sarfti-fall-2013/tree/AnnPonomareva" aria-label="Code" class="selected js-selected-navigation-item sunken-menu-item" data-gotokey="c" data-pjax="true" data-selected-links="repo_source repo_downloads repo_commits repo_tags repo_branches /vsysoev/sarfti-fall-2013/tree/AnnPonomareva">
          <span class="octicon octicon-code"></span> <span class="full-word">Code</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

        <li class="tooltipped leftwards" title="Issues">
          <a href="/vsysoev/sarfti-fall-2013/issues" aria-label="Issues" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-gotokey="i" data-selected-links="repo_issues /vsysoev/sarfti-fall-2013/issues">
            <span class="octicon octicon-issue-opened"></span> <span class="full-word">Issues</span>
            <span class='counter'>2</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>        </li>

      <li class="tooltipped leftwards" title="Pull Requests">
        <a href="/vsysoev/sarfti-fall-2013/pulls" aria-label="Pull Requests" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-gotokey="p" data-selected-links="repo_pulls /vsysoev/sarfti-fall-2013/pulls">
            <span class="octicon octicon-git-pull-request"></span> <span class="full-word">Pull Requests</span>
            <span class='counter'>2</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>


        <li class="tooltipped leftwards" title="Wiki">
          <a href="/vsysoev/sarfti-fall-2013/wiki" aria-label="Wiki" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="repo_wiki /vsysoev/sarfti-fall-2013/wiki">
            <span class="octicon octicon-book"></span> <span class="full-word">Wiki</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>        </li>
    </ul>
    <div class="sunken-menu-separator"></div>
    <ul class="sunken-menu-group">

      <li class="tooltipped leftwards" title="Pulse">
        <a href="/vsysoev/sarfti-fall-2013/pulse" aria-label="Pulse" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="pulse /vsysoev/sarfti-fall-2013/pulse">
          <span class="octicon octicon-pulse"></span> <span class="full-word">Pulse</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

      <li class="tooltipped leftwards" title="Graphs">
        <a href="/vsysoev/sarfti-fall-2013/graphs" aria-label="Graphs" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="repo_graphs repo_contributors /vsysoev/sarfti-fall-2013/graphs">
          <span class="octicon octicon-graph"></span> <span class="full-word">Graphs</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

      <li class="tooltipped leftwards" title="Network">
        <a href="/vsysoev/sarfti-fall-2013/network" aria-label="Network" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-selected-links="repo_network /vsysoev/sarfti-fall-2013/network">
          <span class="octicon octicon-git-branch"></span> <span class="full-word">Network</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>
    </ul>


  </div>
</div>

              <div class="only-with-full-nav">
                

  

<div class="clone-url open"
  data-protocol-type="http"
  data-url="/users/set_protocol?protocol_selector=http&amp;protocol_type=push">
  <h3><strong>HTTPS</strong> clone URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="https://github.com/vsysoev/sarfti-fall-2013.git" readonly="readonly">

    <span class="js-zeroclipboard url-box-clippy minibutton zeroclipboard-button" data-clipboard-text="https://github.com/vsysoev/sarfti-fall-2013.git" data-copied-hint="copied!" title="copy to clipboard"><span class="octicon octicon-clippy"></span></span>
  </div>
</div>

  

<div class="clone-url "
  data-protocol-type="ssh"
  data-url="/users/set_protocol?protocol_selector=ssh&amp;protocol_type=push">
  <h3><strong>SSH</strong> clone URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="git@github.com:vsysoev/sarfti-fall-2013.git" readonly="readonly">

    <span class="js-zeroclipboard url-box-clippy minibutton zeroclipboard-button" data-clipboard-text="git@github.com:vsysoev/sarfti-fall-2013.git" data-copied-hint="copied!" title="copy to clipboard"><span class="octicon octicon-clippy"></span></span>
  </div>
</div>

  

<div class="clone-url "
  data-protocol-type="subversion"
  data-url="/users/set_protocol?protocol_selector=subversion&amp;protocol_type=push">
  <h3><strong>Subversion</strong> checkout URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="https://github.com/vsysoev/sarfti-fall-2013" readonly="readonly">

    <span class="js-zeroclipboard url-box-clippy minibutton zeroclipboard-button" data-clipboard-text="https://github.com/vsysoev/sarfti-fall-2013" data-copied-hint="copied!" title="copy to clipboard"><span class="octicon octicon-clippy"></span></span>
  </div>
</div>


<p class="clone-options">You can clone with
      <a href="#" class="js-clone-selector" data-protocol="http">HTTPS</a>,
      <a href="#" class="js-clone-selector" data-protocol="ssh">SSH</a>,
      or <a href="#" class="js-clone-selector" data-protocol="subversion">Subversion</a>.
  <span class="octicon help tooltipped upwards" title="Get help on which URL is right for you.">
    <a href="https://help.github.com/articles/which-remote-url-should-i-use">
    <span class="octicon octicon-question"></span>
    </a>
  </span>
</p>


  <a href="http://windows.github.com" class="minibutton sidebar-button">
    <span class="octicon octicon-device-desktop"></span>
    Clone in Desktop
  </a>

                <a href="/vsysoev/sarfti-fall-2013/archive/AnnPonomareva.zip"
                   class="minibutton sidebar-button"
                   title="Download this repository as a zip file"
                   rel="nofollow">
                  <span class="octicon octicon-cloud-download"></span>
                  Download ZIP
                </a>
              </div>
        </div><!-- /.repository-sidebar -->

        <div id="js-repo-pjax-container" class="repository-content context-loader-container" data-pjax-container>
          


<!-- blob contrib key: blob_contributors:v21:e67667d4ea95753fa50438d52067dbf9 -->

<p title="This is a placeholder element" class="js-history-link-replace hidden"></p>

<a href="/vsysoev/sarfti-fall-2013/find/AnnPonomareva" data-pjax data-hotkey="t" class="js-show-file-finder" style="display:none">Show File Finder</a>

<div class="file-navigation">
  

<div class="select-menu js-menu-container js-select-menu" >
  <span class="minibutton select-menu-button js-menu-target" data-hotkey="w"
    data-master-branch="master"
    data-ref="AnnPonomareva"
    role="button" aria-label="Switch branches or tags" tabindex="0">
    <span class="octicon octicon-git-branch"></span>
    <i>branch:</i>
    <span class="js-select-button">AnnPonomareva</span>
  </span>

  <div class="select-menu-modal-holder js-menu-content js-navigation-container" data-pjax>

    <div class="select-menu-modal">
      <div class="select-menu-header">
        <span class="select-menu-title">Switch branches/tags</span>
        <span class="octicon octicon-remove-close js-menu-close"></span>
      </div> <!-- /.select-menu-header -->

      <div class="select-menu-filters">
        <div class="select-menu-text-filter">
          <input type="text" aria-label="Find or create a branch…" id="context-commitish-filter-field" class="js-filterable-field js-navigation-enable" placeholder="Find or create a branch…">
        </div>
        <div class="select-menu-tabs">
          <ul>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="branches" class="js-select-menu-tab">Branches</a>
            </li>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="tags" class="js-select-menu-tab">Tags</a>
            </li>
          </ul>
        </div><!-- /.select-menu-tabs -->
      </div><!-- /.select-menu-filters -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="branches">

        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/vsysoev/sarfti-fall-2013/blob/AAbanov_ht4/task_6/aggregation/aggregation.cpp"
                 data-name="AAbanov_ht4"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="AAbanov_ht4">AAbanov_ht4</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/vsysoev/sarfti-fall-2013/blob/AKorezin_1/task_6/aggregation/aggregation.cpp"
                 data-name="AKorezin_1"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="AKorezin_1">AKorezin_1</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/vsysoev/sarfti-fall-2013/blob/AKorezin_ht4/task_6/aggregation/aggregation.cpp"
                 data-name="AKorezin_ht4"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="AKorezin_ht4">AKorezin_ht4</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/vsysoev/sarfti-fall-2013/blob/APonomareva_ht4/task_6/aggregation/aggregation.cpp"
                 data-name="APonomareva_ht4"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="APonomareva_ht4">APonomareva_ht4</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/vsysoev/sarfti-fall-2013/blob/AndreyAbanov/task_6/aggregation/aggregation.cpp"
                 data-name="AndreyAbanov"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="AndreyAbanov">AndreyAbanov</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/vsysoev/sarfti-fall-2013/blob/AndreyAbanov_task8/task_6/aggregation/aggregation.cpp"
                 data-name="AndreyAbanov_task8"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="AndreyAbanov_task8">AndreyAbanov_task8</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item selected">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/vsysoev/sarfti-fall-2013/blob/AnnPonomareva/task_6/aggregation/aggregation.cpp"
                 data-name="AnnPonomareva"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="AnnPonomareva">AnnPonomareva</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/vsysoev/sarfti-fall-2013/blob/ELydaev/task_6/aggregation/aggregation.cpp"
                 data-name="ELydaev"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="ELydaev">ELydaev</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/vsysoev/sarfti-fall-2013/blob/OMoskaeva/task_6/aggregation/aggregation.cpp"
                 data-name="OMoskaeva"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="OMoskaeva">OMoskaeva</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/vsysoev/sarfti-fall-2013/blob/OMoskaeva_ht4/task_6/aggregation/aggregation.cpp"
                 data-name="OMoskaeva_ht4"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="OMoskaeva_ht4">OMoskaeva_ht4</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/vsysoev/sarfti-fall-2013/blob/VAgapkin/task_6/aggregation/aggregation.cpp"
                 data-name="VAgapkin"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="VAgapkin">VAgapkin</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/vsysoev/sarfti-fall-2013/blob/VAgapkin_ht4/task_6/aggregation/aggregation.cpp"
                 data-name="VAgapkin_ht4"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="VAgapkin_ht4">VAgapkin_ht4</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/vsysoev/sarfti-fall-2013/blob/master/task_6/aggregation/aggregation.cpp"
                 data-name="master"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="master">master</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/vsysoev/sarfti-fall-2013/blob/vsysoev/task_6/aggregation/aggregation.cpp"
                 data-name="vsysoev"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="vsysoev">vsysoev</a>
            </div> <!-- /.select-menu-item -->
        </div>

          <form accept-charset="UTF-8" action="/vsysoev/sarfti-fall-2013/branches" class="js-create-branch select-menu-item select-menu-new-item-form js-navigation-item js-new-item-form" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="I/3NsWlEhoufgGKObzq0tXJ4iEEqO6YQAzh8kRzkRZg=" /></div>
            <span class="octicon octicon-git-branch-create select-menu-item-icon"></span>
            <div class="select-menu-item-text">
              <h4>Create branch: <span class="js-new-item-name"></span></h4>
              <span class="description">from ‘AnnPonomareva’</span>
            </div>
            <input type="hidden" name="name" id="name" class="js-new-item-value">
            <input type="hidden" name="branch" id="branch" value="AnnPonomareva" />
            <input type="hidden" name="path" id="path" value="task_6/aggregation/aggregation.cpp" />
          </form> <!-- /.select-menu-item -->

      </div> <!-- /.select-menu-list -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="tags">
        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


        </div>

        <div class="select-menu-no-results">Nothing to show</div>
      </div> <!-- /.select-menu-list -->

    </div> <!-- /.select-menu-modal -->
  </div> <!-- /.select-menu-modal-holder -->
</div> <!-- /.select-menu -->

  <div class="breadcrumb">
    <span class='repo-root js-repo-root'><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/vsysoev/sarfti-fall-2013/tree/AnnPonomareva" data-branch="AnnPonomareva" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">sarfti-fall-2013</span></a></span></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/vsysoev/sarfti-fall-2013/tree/AnnPonomareva/task_6" data-branch="AnnPonomareva" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">task_6</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/vsysoev/sarfti-fall-2013/tree/AnnPonomareva/task_6/aggregation" data-branch="AnnPonomareva" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">aggregation</span></a></span><span class="separator"> / </span><strong class="final-path">aggregation.cpp</strong> <span class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="task_6/aggregation/aggregation.cpp" data-copied-hint="copied!" title="copy to clipboard"><span class="octicon octicon-clippy"></span></span>
  </div>
</div>


  <div class="commit file-history-tease">
    <img alt="AnnPonomareva" class="main-avatar" height="24" src="https://1.gravatar.com/avatar/88faa89732a238fd2dfeaf2247e7ea27?d=https%3A%2F%2Fidenticons.github.com%2F43ab26c420e26be81dc51e6bd343869f.png&amp;r=x&amp;s=140" width="24" />
    <span class="author"><a href="/AnnPonomareva" rel="author">AnnPonomareva</a></span>
    <time class="js-relative-date" datetime="2013-10-28T08:38:40-07:00" title="2013-10-28 08:38:40">October 28, 2013</time>
    <div class="commit-title">
        <a href="/vsysoev/sarfti-fall-2013/commit/d6cf956dcda838bb27e06ed035aaf089051448f5" class="message" data-pjax="true" title="Update aggregation.cpp">Update aggregation.cpp</a>
    </div>

    <div class="participation">
      <p class="quickstat"><a href="#blob_contributors_box" rel="facebox"><strong>1</strong> contributor</a></p>
      
    </div>
    <div id="blob_contributors_box" style="display:none">
      <h2 class="facebox-header">Users who have contributed to this file</h2>
      <ul class="facebox-user-list">
          <li class="facebox-user-list-item">
            <img alt="AnnPonomareva" height="24" src="https://1.gravatar.com/avatar/88faa89732a238fd2dfeaf2247e7ea27?d=https%3A%2F%2Fidenticons.github.com%2F43ab26c420e26be81dc51e6bd343869f.png&amp;r=x&amp;s=140" width="24" />
            <a href="/AnnPonomareva">AnnPonomareva</a>
          </li>
      </ul>
    </div>
  </div>

<div id="files" class="bubble">
  <div class="file">
    <div class="meta">
      <div class="info">
        <span class="icon"><b class="octicon octicon-file-text"></b></span>
        <span class="mode" title="File Mode">file</span>
          <span>64 lines (54 sloc)</span>
        <span>1.169 kb</span>
      </div>
      <div class="actions">
        <div class="button-group">
            <a class="minibutton tooltipped leftwards"
               href="http://windows.github.com" title="Open this file in GitHub for Windows">
                <span class="octicon octicon-device-desktop"></span> Open
            </a>
                <a class="minibutton js-update-url-with-hash"
                   href="/vsysoev/sarfti-fall-2013/edit/AnnPonomareva/task_6/aggregation/aggregation.cpp"
                   data-method="post" rel="nofollow" data-hotkey="e">Edit</a>
          <a href="/vsysoev/sarfti-fall-2013/raw/AnnPonomareva/task_6/aggregation/aggregation.cpp" class="button minibutton " id="raw-url">Raw</a>
            <a href="/vsysoev/sarfti-fall-2013/blame/AnnPonomareva/task_6/aggregation/aggregation.cpp" class="button minibutton js-update-url-with-hash">Blame</a>
          <a href="/vsysoev/sarfti-fall-2013/commits/AnnPonomareva/task_6/aggregation/aggregation.cpp" class="button minibutton " rel="nofollow">History</a>
        </div><!-- /.button-group -->
          <a class="minibutton danger empty-icon tooltipped downwards"
             href="/vsysoev/sarfti-fall-2013/delete/AnnPonomareva/task_6/aggregation/aggregation.cpp"
             title=""
             data-method="post" data-test-id="delete-blob-file" rel="nofollow">
          Delete
        </a>
      </div><!-- /.actions -->
    </div>
        <div class="blob-wrapper data type-c js-blob-data">
        <table class="file-code file-diff tab-size-8">
          <tr class="file-code-line">
            <td class="blob-line-nums">
              <span id="L1" rel="#L1">1</span>
<span id="L2" rel="#L2">2</span>
<span id="L3" rel="#L3">3</span>
<span id="L4" rel="#L4">4</span>
<span id="L5" rel="#L5">5</span>
<span id="L6" rel="#L6">6</span>
<span id="L7" rel="#L7">7</span>
<span id="L8" rel="#L8">8</span>
<span id="L9" rel="#L9">9</span>
<span id="L10" rel="#L10">10</span>
<span id="L11" rel="#L11">11</span>
<span id="L12" rel="#L12">12</span>
<span id="L13" rel="#L13">13</span>
<span id="L14" rel="#L14">14</span>
<span id="L15" rel="#L15">15</span>
<span id="L16" rel="#L16">16</span>
<span id="L17" rel="#L17">17</span>
<span id="L18" rel="#L18">18</span>
<span id="L19" rel="#L19">19</span>
<span id="L20" rel="#L20">20</span>
<span id="L21" rel="#L21">21</span>
<span id="L22" rel="#L22">22</span>
<span id="L23" rel="#L23">23</span>
<span id="L24" rel="#L24">24</span>
<span id="L25" rel="#L25">25</span>
<span id="L26" rel="#L26">26</span>
<span id="L27" rel="#L27">27</span>
<span id="L28" rel="#L28">28</span>
<span id="L29" rel="#L29">29</span>
<span id="L30" rel="#L30">30</span>
<span id="L31" rel="#L31">31</span>
<span id="L32" rel="#L32">32</span>
<span id="L33" rel="#L33">33</span>
<span id="L34" rel="#L34">34</span>
<span id="L35" rel="#L35">35</span>
<span id="L36" rel="#L36">36</span>
<span id="L37" rel="#L37">37</span>
<span id="L38" rel="#L38">38</span>
<span id="L39" rel="#L39">39</span>
<span id="L40" rel="#L40">40</span>
<span id="L41" rel="#L41">41</span>
<span id="L42" rel="#L42">42</span>
<span id="L43" rel="#L43">43</span>
<span id="L44" rel="#L44">44</span>
<span id="L45" rel="#L45">45</span>
<span id="L46" rel="#L46">46</span>
<span id="L47" rel="#L47">47</span>
<span id="L48" rel="#L48">48</span>
<span id="L49" rel="#L49">49</span>
<span id="L50" rel="#L50">50</span>
<span id="L51" rel="#L51">51</span>
<span id="L52" rel="#L52">52</span>
<span id="L53" rel="#L53">53</span>
<span id="L54" rel="#L54">54</span>
<span id="L55" rel="#L55">55</span>
<span id="L56" rel="#L56">56</span>
<span id="L57" rel="#L57">57</span>
<span id="L58" rel="#L58">58</span>
<span id="L59" rel="#L59">59</span>
<span id="L60" rel="#L60">60</span>
<span id="L61" rel="#L61">61</span>
<span id="L62" rel="#L62">62</span>
<span id="L63" rel="#L63">63</span>

            </td>
            <td class="blob-line-code"><div class="code-body highlight"><pre><div class='line' id='LC1'><span class="cp">#include &lt;iostream&gt;</span></div><div class='line' id='LC2'><span class="cp">#include &lt;conio.h&gt;</span></div><div class='line' id='LC3'><br/></div><div class='line' id='LC4'><span class="k">using</span> <span class="k">namespace</span> <span class="n">std</span><span class="p">;</span></div><div class='line' id='LC5'><br/></div><div class='line' id='LC6'><span class="k">class</span> <span class="nc">Class_1</span> <span class="c1">//внешний класс</span></div><div class='line' id='LC7'><span class="p">{</span></div><div class='line' id='LC8'>&nbsp;<span class="nl">private:</span> <span class="c1">//закрытые объекты( main &quot;не видит&quot;)</span></div><div class='line' id='LC9'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">b</span><span class="p">;</span></div><div class='line' id='LC10'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">Class_AGR</span> <span class="o">*</span><span class="n">aggregated</span><span class="p">;</span> <span class="c1">//указатель на агрегируемый объект</span></div><div class='line' id='LC11'><span class="nl">public:</span></div><div class='line' id='LC12'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">void</span> <span class="nf">one_B</span><span class="p">(</span><span class="kt">int</span> <span class="n">b1</span><span class="p">)</span></div><div class='line' id='LC13'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC14'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">b</span><span class="o">=</span><span class="n">b1</span><span class="o">+</span><span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC15'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">};</span></div><div class='line' id='LC16'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC17'>&nbsp;&nbsp;&nbsp;<span class="n">Class_1</span><span class="p">(</span><span class="n">Class_AGR</span> <span class="o">*</span><span class="n">aggregated_1</span><span class="o">=</span><span class="nb">NULL</span><span class="p">,</span><span class="kt">int</span> <span class="n">b1</span><span class="o">=</span><span class="mi">5</span><span class="p">)</span><span class="o">:</span><span class="n">aggregated</span><span class="p">(</span><span class="n">aggregated_1</span><span class="p">),</span><span class="n">b</span><span class="p">(</span><span class="n">b1</span><span class="p">);</span></div><div class='line' id='LC18'>&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC19'>&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="nf">two_B</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span></div><div class='line' id='LC20'>&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC21'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">return</span> <span class="n">b</span><span class="p">;</span></div><div class='line' id='LC22'>&nbsp;&nbsp;&nbsp;<span class="p">};</span></div><div class='line' id='LC23'>&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC24'>&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="nf">two_A</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span></div><div class='line' id='LC25'>&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC26'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">return</span> <span class="n">aggregated</span><span class="o">-&gt;</span><span class="n">two_A</span><span class="p">();</span></div><div class='line' id='LC27'>&nbsp;&nbsp;&nbsp;<span class="p">};</span></div><div class='line' id='LC28'>&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC29'>&nbsp;&nbsp;<span class="kt">void</span> <span class="nf">one_A</span><span class="p">(</span><span class="kt">int</span> <span class="n">a1</span><span class="p">)</span></div><div class='line' id='LC30'>&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC31'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aggregated</span><span class="o">-&gt;</span><span class="n">one_A</span><span class="p">(</span><span class="n">a1</span><span class="p">);</span></div><div class='line' id='LC32'>&nbsp;&nbsp;<span class="p">};</span></div><div class='line' id='LC33'><span class="p">};</span></div><div class='line' id='LC34'><br/></div><div class='line' id='LC35'><br/></div><div class='line' id='LC36'><span class="k">class</span> <span class="nc">Class_AGR</span><span class="c1">//агрегируемый класс</span></div><div class='line' id='LC37'><span class="p">{</span></div><div class='line' id='LC38'><span class="nl">public:</span></div><div class='line' id='LC39'>&nbsp;&nbsp;<span class="kt">void</span> <span class="n">one_A</span><span class="p">(</span><span class="kt">int</span> <span class="n">a1</span><span class="p">)</span></div><div class='line' id='LC40'>&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC41'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span><span class="o">=</span><span class="n">a1</span><span class="o">+</span><span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC42'>&nbsp;&nbsp;&nbsp;<span class="p">};</span></div><div class='line' id='LC43'>&nbsp;&nbsp;<span class="n">Class_AGR</span><span class="p">(</span><span class="kt">int</span> <span class="n">a1</span><span class="o">=</span><span class="mi">5</span><span class="p">)</span><span class="o">:</span><span class="n">a</span><span class="p">(</span><span class="n">a1</span><span class="p">);</span></div><div class='line' id='LC44'>&nbsp;&nbsp;<span class="kt">int</span> <span class="nf">two_A</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span></div><div class='line' id='LC45'>&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC46'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">return</span> <span class="n">a</span><span class="p">;</span></div><div class='line' id='LC47'>&nbsp;&nbsp;&nbsp;<span class="p">};</span></div><div class='line' id='LC48'><span class="nl">private:</span> <span class="c1">//закрытые объекты</span></div><div class='line' id='LC49'>&nbsp;&nbsp;<span class="kt">int</span> <span class="n">a</span><span class="p">;</span></div><div class='line' id='LC50'><span class="p">};</span></div><div class='line' id='LC51'><br/></div><div class='line' id='LC52'><span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span></div><div class='line' id='LC53'><span class="p">{</span></div><div class='line' id='LC54'>&nbsp;&nbsp;<span class="n">Class_AGR</span> <span class="o">*</span><span class="n">aggregated_1</span> <span class="o">=</span> <span class="k">new</span> <span class="n">Class_AGR</span><span class="p">();</span></div><div class='line' id='LC55'>&nbsp;&nbsp;<span class="n">Class_1</span> <span class="n">aggregated_2</span><span class="p">(</span><span class="n">aggregated_1</span><span class="p">);</span></div><div class='line' id='LC56'>&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="n">aggregated_2</span><span class="p">.</span><span class="n">two_B</span><span class="p">()</span><span class="o">&lt;&lt;</span><span class="s">&quot;/n&quot;</span><span class="o">&lt;&lt;</span> <span class="n">aaggregated_2</span><span class="p">.</span><span class="n">two_A</span><span class="p">()</span><span class="o">&lt;&lt;</span><span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC57'>&nbsp;&nbsp;<span class="n">aggregated_2</span><span class="p">.</span><span class="n">one_A</span><span class="p">();</span></div><div class='line' id='LC58'>&nbsp;&nbsp;<span class="n">aggregated_2</span><span class="p">.</span><span class="n">one_B</span><span class="p">();</span></div><div class='line' id='LC59'>&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="n">aggregated_2</span><span class="p">.</span><span class="n">two_</span><span class="err">В</span><span class="p">()</span><span class="o">&lt;&lt;</span><span class="s">&quot;/n&quot;</span><span class="o">&lt;&lt;</span> <span class="n">aaggregated_2</span><span class="p">.</span><span class="n">two_A</span><span class="p">()</span><span class="o">&lt;&lt;</span><span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC60'>&nbsp;&nbsp;<span class="k">delete</span> <span class="n">aaggregated_1</span><span class="p">;</span></div><div class='line' id='LC61'>&nbsp;&nbsp;<span class="k">return</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC62'>&nbsp;&nbsp;<span class="n">getch</span><span class="p">();</span></div><div class='line' id='LC63'><span class="p">}</span></div></pre></div></td>
          </tr>
        </table>
  </div>

  </div>
</div>

<a href="#jump-to-line" rel="facebox[.linejump]" data-hotkey="l" class="js-jump-to-line" style="display:none">Jump to Line</a>
<div id="jump-to-line" style="display:none">
  <form accept-charset="UTF-8" class="js-jump-to-line-form">
    <input class="linejump-input js-jump-to-line-field" type="text" placeholder="Jump to line&hellip;" autofocus>
    <button type="submit" class="button">Go</button>
  </form>
</div>

        </div>

      </div><!-- /.repo-container -->
      <div class="modal-backdrop"></div>
    </div><!-- /.container -->
  </div><!-- /.site -->


    </div><!-- /.wrapper -->

      <div class="container">
  <div class="site-footer">
    <ul class="site-footer-links right">
      <li><a href="https://status.github.com/">Status</a></li>
      <li><a href="http://developer.github.com">API</a></li>
      <li><a href="http://training.github.com">Training</a></li>
      <li><a href="http://shop.github.com">Shop</a></li>
      <li><a href="/blog">Blog</a></li>
      <li><a href="/about">About</a></li>

    </ul>

    <a href="/">
      <span class="mega-octicon octicon-mark-github" title="GitHub"></span>
    </a>

    <ul class="site-footer-links">
      <li>&copy; 2014 <span title="0.03661s from github-fe139-cp1-prd.iad.github.net">GitHub</span>, Inc.</li>
        <li><a href="/site/terms">Terms</a></li>
        <li><a href="/site/privacy">Privacy</a></li>
        <li><a href="/security">Security</a></li>
        <li><a href="/contact">Contact</a></li>
    </ul>
  </div><!-- /.site-footer -->
</div><!-- /.container -->


    <div class="fullscreen-overlay js-fullscreen-overlay" id="fullscreen_overlay">
  <div class="fullscreen-container js-fullscreen-container">
    <div class="textarea-wrap">
      <textarea name="fullscreen-contents" id="fullscreen-contents" class="js-fullscreen-contents" placeholder="" data-suggester="fullscreen_suggester"></textarea>
          <div class="suggester-container">
              <div class="suggester fullscreen-suggester js-navigation-container" id="fullscreen_suggester"
                 data-url="/vsysoev/sarfti-fall-2013/suggestions/commit">
              </div>
          </div>
    </div>
  </div>
  <div class="fullscreen-sidebar">
    <a href="#" class="exit-fullscreen js-exit-fullscreen tooltipped leftwards" title="Exit Zen Mode">
      <span class="mega-octicon octicon-screen-normal"></span>
    </a>
    <a href="#" class="theme-switcher js-theme-switcher tooltipped leftwards"
      title="Switch themes">
      <span class="octicon octicon-color-mode"></span>
    </a>
  </div>
</div>



    <div id="ajax-error-message" class="flash flash-error">
      <span class="octicon octicon-alert"></span>
      <a href="#" class="octicon octicon-remove-close close js-ajax-error-dismiss"></a>
      Something went wrong with that request. Please try again.
    </div>

  </body>
</html>

