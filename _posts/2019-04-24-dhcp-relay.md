---

subtitle:    "subtitle"
author:      "author"
description: "Dhcp Relay"
header-mask: 0.5
catalog: ture
multilingual: true
header-img:  "img/home-bg.jpg"
tags:
    - SERVER

---


<!-- Chinese Version -->
<div class="zh post-container">
    {% capture about_zh %}
        {% include post/protocol/dhcp_relay.md %}
     {% endcapture %}
    {{ about_zh | markdownify }}
</div>

<!-- English Version -->
<div class="en post-container">
    {% capture about_en %}
        {% include post/protocol/dhcp_relay.md %}
    {% endcapture %}
    {{ about_en | markdownify }}
</div>
