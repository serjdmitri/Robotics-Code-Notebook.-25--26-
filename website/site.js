if ('IntersectionObserver' in window && !matchMedia('(prefers-reduced-motion: reduce)').matches) {
  const cards = document.querySelectorAll('.tile, .reveal');
  const observer = new IntersectionObserver(entries => entries.forEach(entry => {
    if (entry.isIntersecting) { entry.target.classList.add('visible'); observer.unobserve(entry.target); }
  }), { threshold: .15 });
  document.documentElement.classList.add('reveal-ready');
  cards.forEach(card => observer.observe(card));
}
document.querySelectorAll('.tile').forEach(card => card.addEventListener('click', event => {
  if (!event.target.closest('a')) card.classList.toggle('expanded');
}));
// Add supplied media here, for example: 'carcomms': {image:'images/carcomms.jpg', video:'images/carcomms.mp4'}.
// Video and GIF are optional; the image is used as a poster and fallback.
const media = {};
document.querySelectorAll('[data-media]').forEach(container => {
  const item = media[container.dataset.media];
  if (!item) return;
  const fallback = () => {
    if (!item.image) return;
    const image = new Image(); image.alt = item.alt || container.dataset.label; image.loading = 'lazy';
    image.onload = () => container.replaceChildren(image);
    image.src = item.image;
  };
  if (item.video) {
    const video = document.createElement('video');
    video.muted = true; video.loop = true; video.autoplay = true; video.playsInline = true; video.preload = 'none';
    if (item.image) video.poster = item.image;
    video.addEventListener('error', fallback); video.src = item.video;
    container.replaceChildren(video);
    video.play().catch(fallback);
  } else if (item.gif) {
    const image = new Image(); image.alt = item.alt || container.dataset.label; image.loading = 'lazy';
    image.onload = () => container.replaceChildren(image); image.onerror = fallback; image.src = item.gif;
  } else fallback();
});
document.querySelectorAll('.gallery-controls button').forEach(button => button.addEventListener('click', () => {
  const gallery = button.closest('.gallery-section').querySelector('.gallery');
  const slide = gallery.querySelector('figure');
  gallery.scrollBy({left: Number(button.dataset.scroll) * (slide.getBoundingClientRect().width + 16), behavior: matchMedia('(prefers-reduced-motion: reduce)').matches ? 'instant' : 'smooth'});
}));
const featuredVideo = document.querySelector('.featured-video');
if (featuredVideo && !matchMedia('(prefers-reduced-motion: reduce)').matches && 'IntersectionObserver' in window) {
  const videoObserver = new IntersectionObserver(entries => entries.forEach(entry => {
    if (entry.isIntersecting) { featuredVideo.play().catch(() => {}); videoObserver.unobserve(featuredVideo); }
  }), {threshold: .4});
  videoObserver.observe(featuredVideo);
}
// Gallery images can be enlarged; native dialog supports keyboard dismissal.
if (typeof HTMLDialogElement !== 'undefined') {
  const dialog = document.createElement('dialog');
  dialog.className = 'image-dialog';
  dialog.setAttribute('aria-label', 'Enlarged gallery image');
  const close = document.createElement('button'); close.type = 'button'; close.setAttribute('aria-label', 'Close image'); close.textContent = '×';
  const large = document.createElement('img');
  const caption = document.createElement('p');
  dialog.append(close, large, caption); document.body.append(dialog);
  close.addEventListener('click', () => dialog.close());
  document.querySelectorAll('.gallery figure').forEach(figure => {
    const img = figure.querySelector('img'); if (!img) return;
    const button = document.createElement('button'); button.type = 'button'; button.className = 'gallery-enlarge';
    button.setAttribute('aria-label', 'Enlarge: ' + img.alt);
    img.before(button); button.append(img);
    button.addEventListener('click', () => {large.src = img.currentSrc || img.src; large.alt = img.alt; caption.textContent = figure.querySelector('figcaption')?.textContent || img.alt; dialog.showModal();});
  });
}
