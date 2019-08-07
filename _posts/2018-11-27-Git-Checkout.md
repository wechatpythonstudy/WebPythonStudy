---

subtitle:    "subtitle"
author:      "author"
description: "Post Template"
header-mask: 0.5
catalog: ture
multilingual: true
header-img:  "img/home-bg.jpg"
tags:
    - GIT

---


<!-- Chinese Version -->
<div class="zh post-container">
    {% capture about_zh %}
        {% include post/git/checkout_zh.md %}
    {% endcapture %}
    {{ about_zh | markdownify }}
</div>

<!-- English Version -->
<div class="en post-container">
    {% capture about_en %}
    {% endcapture %}
    {{ about_en | markdownify }}
</div>
